int test(int arg1, int arg2)
{
    int ret = arg1 - arg2;
    int sign_full = ret >> 31;
    ret = (ret + sign_full) >> 1;
    sign_full = ret + arg2;
    if (sign_full <= edi)
    {
        ret = 0;
        if (sign_full >= edi)
        {
            // 401007
            return ret;
        }
        else
        {
            arg2 = sign_full + 0x1;
            test(arg1, arg2);
            ret = ret * 2 + 1;
            return ret;
        }
    }
    else
    {
        arg1 = sign_full - 0x1;
        test(arg1, arg2);
        ret = ret * 2;
        return ret;
    }
}