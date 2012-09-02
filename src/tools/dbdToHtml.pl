#!/usr/bin/perl
#*************************************************************************
# Copyright (c) 2010 UChicago Argonne LLC, as Operator of Argonne
#     National Laboratory.
# EPICS BASE is distributed subject to a Software License Agreement found
# in file LICENSE that is included with this distribution.
#*************************************************************************

# $Id$

use FindBin qw($Bin);
use lib "$Bin/../../lib/perl";

use DBD;
use DBD::Parser;
use EPICS::Getopts;
use EPICS::macLib;
use EPICS::Readfile;
use Pod::Simple::HTML;

my $tool = 'dbdToHtml';
getopts('DI@o:') or
    die "Usage: $tool [-D] [-I dir] [-o file.html] file.dbd\n";

my $dbd = DBD->new();

my $infile = shift @ARGV;
$infile =~ m/\.dbd$/ or
    die "$tool: Input file '$infile' must have '.dbd' extension\n";

&ParseDBD($dbd, &Readfile($infile, 0, \@opt_I));

if (!$opt_o) {
    ($opt_o = $infile) =~ s/\.dbd$/.html/;
    $opt_o =~ s/^.*\///;
    $opt_o =~ s/dbCommonRecord/dbCommon/;
}

if ($opt_D) {   # Output dependencies only
    my %filecount;
    my @uniqfiles = grep { not $filecount{$_}++ } @inputfiles;
    print "$opt_o: ", join(" \\\n    ", @uniqfiles), "\n\n";
    print map { "$_:\n" } @uniqfiles;
    exit 0;
}

open my $out, '>', $opt_o or die "Can't create $opt_o: $!\n";

# Grab the comments from the root DBD object
# Strip a single leading space off all comment lines
my @pod = map { s/^ //; $_ } $dbd->comments;

my $rtypes = $dbd->recordtypes;

# Process the comments from any record types defined
while (my ($rn, $rtyp) = each %{$rtypes}) {
    foreach my $_ ($rtyp->comments) {
        # Strip a single leading space
        s/^ //;
        # Handle our 'fields' Pod directive
        if (m/^=fields (.*)/) {
            my @names = split /\s*,\s*/, $1;
	    # Look up every named field
            my @fields = map {
                    my $field = $rtyp->field($_);
                    print STDERR "Unknown field name '$_' in $infile POD\n" unless $field;
                    $field;
                } @names;
            my $html;
	    # Generate a HTML table row for each field
            foreach $field (@fields) {
                $html .= $field->htmlTableRow if $field;
            }
	    # Add the complete table
            push @pod, podTable($html);
        }
        else {
	    # Add other comments
            push @pod, $_;
        }
    }
}

my $podHtml = Pod::Simple::HTML->new();
$podHtml->html_css('style.css');
$podHtml->perldoc_url_prefix('');
$podHtml->perldoc_url_postfix('.html');
$podHtml->set_source(\@pod);
# $podHtml->index(1);
$podHtml->output_string(\my $html);
$podHtml->run;
print $out $html;
close $out;


sub podTable {
    my $content = shift;
    return ("=begin html\n", "\n",
        "<blockquote><table border =\"1\"><tr>\n",
        "<th>Field</th><th>Summary</th><th>Type</th><th>DCT</th>",
        "<th>Default</th><th>Read</th><th>Write</th><th>CA PP</th></tr>\n",
        $content, "</table></blockquote>\n",
        "\n", "=end html\n");
}

sub DBD::Recfield::htmlTableRow {
    my $fld = shift;
    my $html = '<tr><td class="cell">';
    $html .= $fld->name;
    $html .= '</td><td class="cell">';
    $html .= $fld->attribute('prompt');
    $html .= '</td><td class="cell">';
    my $type = $fld->public_type;
    $html .= $type;
    $html .= ' [' . $fld->attribute('size') . ']'
        if $type eq 'STRING';
    $html .= ' (' . $fld->attribute('menu') . ')'
        if $type eq 'MENU';
    $html .= '</td><td class="cell">';
    $html .= $fld->attribute('promptgroup') ? 'Yes' : 'No';
    $html .= '</td><td class="cell">';
    $html .= $fld->attribute('initial') || '&nbsp;';
    $html .= '</td><td class="cell">';
    $html .= $fld->readable;
    $html .= '</td><td class="cell">';
    $html .= $fld->writable;
    $html .= '</td><td class="cell">';
    $html .= $fld->attribute('pp') eq "TRUE" ? 'Yes' : 'No';
    $html .= "</td></tr>\n";
    return $html;
}

# Native type presented to dbAccess users
sub DBD::Recfield::public_type {
    my $fld = shift;
    m/^=type (.+)$/i && return $1 for $fld->comments;
    my $type = $fld->dbf_type;
    $type =~ s/^DBF_//;
    return $type;
}

# Check if this field is readable
sub DBD::Recfield::readable {
    my $fld = shift;
    m/^=read (Yes|No)$/i && return $1 for $fld->comments;
    return 'Probably'
        if $fld->attribute('special') eq "SPC_DBADDR";
    return $fld->dbf_type eq 'DBF_NOACCESS' ? 'No' : 'Yes';
}

# Check if this field is writable
sub DBD::Recfield::writable {
    my $fld = shift;
    m/^=write (Yes|No)$/i && return $1 for $fld->comments;
    my $special = $fld->attribute('special');
    return 'No'
        if $special eq "SPC_NOMOD";
    return 'Maybe'
        if $special eq "SPC_DBADDR";
    return $fld->dbf_type eq "DBF_NOACCESS" ? 'No' : 'Yes';
}

