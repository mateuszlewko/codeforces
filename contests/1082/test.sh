for i in {1..1000}
do
  python3 gen_b.py > in.txt
  ./b_rade < in.txt > out_rade.txt
  ./b < in.txt > out_tested.txt

  if diff -w ./out_rade.txt ./out_tested.txt
  then 
    echo $i OK
  else 
    echo FAIL
    exit 1
  fi 
done
