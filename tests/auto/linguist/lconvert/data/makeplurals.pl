#!/usr/bin/env perl
#############################################################################
##
## Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
## All rights reserved.
## Contact: Nokia Corporation (qt-info@nokia.com)
##
## This file is part of the test suite of the Qt Toolkit.
##
## $QT_BEGIN_LICENSE:LGPL$
## No Commercial Usage
## This file contains pre-release code and may not be distributed.
## You may use this file in accordance with the terms and conditions
## contained in the Technology Preview License Agreement accompanying
## this package.
##
## GNU Lesser General Public License Usage
## Alternatively, this file may be used under the terms of the GNU Lesser
## General Public License version 2.1 as published by the Free Software
## Foundation and appearing in the file LICENSE.LGPL included in the
## packaging of this file.  Please review the following information to
## ensure the GNU Lesser General Public License version 2.1 requirements
## will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
##
## In addition, as a special exception, Nokia gives you certain additional
## rights.  These rights are described in the Nokia Qt LGPL Exception
## version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
##
## If you have questions regarding the use of this file, please contact
## Nokia at qt-info@nokia.com.
##
##
##
##
##
##
##
##
## $QT_END_LICENSE$
##
#############################################################################

sub makeit2($$$)
{
    for (my $i = 0; $i < (1 << $_[0]); $i++) {
        print OUTFILE "\n";
        print OUTFILE "$_[2]\n" unless $3 eq "";
        print OUTFILE "msgid \"singular $_[1] $i\"\n";
        print OUTFILE "msgid_plural \"plural $_[1] $i\"\n";
        for (my $j = 0; $j < $_[0]; $j++) {
            my $tr;
            if (($i & (1 << $j)) == 0) {
                $tr = "translated $_[1] $i $j";
            }
            print OUTFILE "msgstr[$j] \"$tr\"\n";
        }
    }
}

sub makeit($$)
{
    open OUTFILE, ">${OUTDIR}plural-$_[0].po" || die "cannot write file in $OUTDIR";
    print OUTFILE <<EOF;
msgid ""
msgstr ""
"X-FooBar: yup\\n"
"X-Language: $_[1]\\n"
EOF
    makeit2($_[0], "one", "");
    makeit2($_[0], "two", "#, fuzzy
#| msgid \"old untranslated one\"");
    makeit2($_[0], "three", "#, fuzzy
#| msgid \"old untranslated two\"
#| msgid_plural \"old untranslated plural two\"");
    makeit2($_[0], "four", "#, fuzzy
#| msgid_plural \"old untranslated only plural three\"");
}

$OUTDIR = $ARGV[0];
makeit(1, "zh_CN");
makeit(2, "de_DE");
makeit(3, "pl_PL");
