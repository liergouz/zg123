
// �����������
int main( object me, string arg )
{
        string *name, result;
        int i, size;

        result = sprintf( "Ŀǰ�Ĵ����У�" );
        name = CLASS_D->get_godlist();
        for( i = 0, size = sizeof(name); i < size; i ++ ) 
                result = sprintf( "%s%s%s��", result, i % 8 ? "" : "\n", name[i] );
        tell_user(me, result);

        result = sprintf( "Ŀǰ�ģǣ��У�" );
        name = CLASS_D->get_gmlist();
        for( i = 0, size = sizeof(name); i < size; i ++ ) 
                result = sprintf( "%s%s%s��", result, i % 8 ? "" : "\n", name[i] );
        tell_user(me, result);
        result = sprintf( "Ŀǰ�ģǣ����ܺ��У�" );
        name = CLASS_D->get_gm2list();
        for( i = 0, size = sizeof(name); i < size; i ++ ) 
                result = sprintf( "%s%s%s��", result, i % 8 ? "" : "\n", name[i] );
        tell_user(me, result);
        result = sprintf( "Ŀǰ�Ļ���У�" );
        name = CLASS_D->get_gm3list();
        for( i = 0, size = sizeof(name); i < size; i ++ ) 
                result = sprintf( "%s%s%s��", result, i % 8 ? "" : "\n", name[i] );
        tell_user(me, result);

        return 1;
}
