#!/bin/bash
make
rm output.txt
objs=`ls test | grep obj`
txts=`ls test | grep txt`
for file in $objs
do
    file=test/$file

done

for file in test/rectest.obj test/strtest.obj test/public-test_checkers_img.obj test/public-test_trap_rti_ldr_str.obj test/rubik.obj test/user_echo.obj test/user_square.obj test/wireframe.obj
do
    result=`echo $file | sed -e "s_.obj_.txt_g" | sed -e "s.test.my_tests.g"`
    output=`echo $file | sed -e "s.obj.txt.g"`
    ./disas $result $file test/os.obj 1> print.txt
    diff -wu $result $output | grep -E "^(\+|\-).*$">> output.txt
done

# for file in test/rectest.obj test/strtest.obj test/public-test_checkers_img.obj test/public-test_trap_rti_ldr_str.obj test/rubik.obj test/user_echo.obj test/user_square.obj test/wireframe.obj
# do
# done
cat output.txt | grep -e "test/.*\.txt" > failed.txt