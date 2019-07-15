
# bash task5.bash 1 3 5

br=1
br=`expr $br \* $2` # br=3

a=$3 # a=5
set ab bc cd de
shift # bc cd de

while true
do
    echo $* # bc cd de

    # for j in bc cd de
    for j
    do
        if test $# -lt $br # 3 < 3 false
        then
            br=`expr $br / 2` # br=4 | br=2
            echo $br $j >> file # 4 cd | 2 de
        else
            br=`expr $br + $a` # br=3+5 = 8
            echo $br $j >> file # 8 bc
        fi
    done
    break
done

read a1 a2 # c d

# file
# 8 bc
# 4 cd
# 2 de

while cat file | grep $a1 # 8 bc | 4 cd
do
    echo $a $a2 # 5 d
    wc -l file # 3 file
    tail -5c file # 2 de
    exit
    echo FIN
done

echo $a $a1 # 5 c
wc -c file # 15 file
tail -2l file # 4 cd | 2 de