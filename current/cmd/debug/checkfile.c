
// �����������
int main( object me, string arg )
{
        mixed *dfile;
        string path, file;
        int i, size;

        if( is_player(me) ) 
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
		return 1;
        }

	if( !arg ) arg = ".";

        path = absolute_path(me, arg);    // ��ȡ����·��
        if( directory_exist(path) && path[<1] != '/' ) path += "/";

        dfile = get_dir(path) - ({ ".", ".." });    // ��ȡ�ļ��б�

        if( !( size = sizeof(dfile) ) ) 
        {
//                notify( "�޷��ҵ�����ļ���" );
		return 1;
	}

        path = path[ 0 .. strchr( path, '/', -1 ) + 1 ];    // �������·��

        if( path[0..5] == "/data/" )
        {
                notify( "����ɨ�� /data Ŀ¼��" );
		return 1;
	}
        if( path[0..4] == "/log/" )
        {
                notify( "����ɨ�� /log Ŀ¼��" );
		return 1;
	}

        tell_user( me, "ɨ��Ŀ¼: %s", path );

        for( i = 0; i < size; i ++ )    // ���������ļ�
        {
                file = path + dfile[i];    // ȡ����·����

                if( directory_exist( file ) ) 
                {
                        main( me, file + "/" );    // ������Ŀ¼
                }
                else 
                {
                        if( file[<2..<1] == ".c" ) 
                        {
                        	"/cmd/debug/update"->main(me, file);
                        }
                }
        }

        return 1;
}
