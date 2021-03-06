import string;
/* Split file into head and tail */
app (file out1) split1 (file inp) {
    "./632-split.sh" @inp @out1 ;
}

app (file out2) merge (file inpt[]) {
    "./632-merg.sh" inpt @stdout=out2;
}


main {
    
file wcounter[];

foreach x in [0:15]
{
  string filename2 = sprintf("input/data%.2d",x);
  file infile = input_file(filename2);
  string filename1 = sprintf("output/data%.2d.txt",x);
  file tail<filename1>;
  tail = split1 (infile);
  wcounter[x] = tail;
}

file merge_out<"output/final-output.out">;
merge_out = merge(wcounter);

//file result <"output/sorted.txt"> = merge(0,9);
}
