#!/usr/bin/env perl
# localhost:4646
use CGI qw{param};
print "Content-type: text/html\n\n";

sub t {
  $nn = $_[1];// A
  $xx = $_[0];// A
  $xx =~ tr/a-z/A-Z/;// Lo pasamos a mayusculas
  $xx =~ s/\s.*//;// Recortamos hasta el primer espacio
  @output = `egrep "$xx" /tmp/xd 2>&1`;// tomamos $xx como patrón para xd
  foreach $line (@output) {
      ($f, $s) = split(/:/, $line);// asignar dos variables a la vez (mapa)
      if($s =~ $nn) {
          return 1;
      }
  }
  return 0;
}

sub n {
  if($_[0] == 1) {
      print("..");
  } else {
      print(".");
  }
}

n(t(param("x"), param("y")));