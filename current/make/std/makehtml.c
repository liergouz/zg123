
#define HTM_FILE        __DIR__ "blank.htm"
#define BEGIN_MARK      "<!-- #### BEGIN #### -->"
#define END_MARK        "<!-- #### END #### -->"

// �����������
int main( object me, string arg )
{
        mixed *dfile;
        string path, file, file2, html, html2, html3, result;
        int p, p2, i, size;

        html = read_file( HTM_FILE );

        if( !( p = strstr(html, BEGIN_MARK, 1) ) ) 
        {
                notify( "�޷��ҵ���ʼ��ǡ�" );
		return 1;
	}
        html2 = html[0..p-1] + BEGIN_MARK + "\n";

        if( !( p = strstr(html, END_MARK, 1) ) ) 
        {
                notify( "�޷��ҵ�������ǡ�" );
		return 1;
	}
        html3 = html[p..<1];

        html = "";

	if( !arg ) arg = "/log/make";

        path = absolute_path(me, arg);    // ��ȡ����·��
        if( directory_exist(path) && path[<1] != '/' ) path += "/";

        dfile = get_dir(path) - ({ ".", ".." });    // ��ȡ�ļ��б�

        if( !( size = sizeof(dfile) ) ) 
        {
                notify( "�޷��ҵ�����ļ���" );
		return 1;
	}

        path = path[ 0 .. strchr( path, '/', -1 ) + 1 ];    // �������·��

        tell_user( me, "ɨ��Ŀ¼: %s\n", path );

        for( i = 0; i < size; i ++ )    // ���������ļ�
        {
                file = path + dfile[i];    // ȡ����·����

                if( directory_exist( file ) ) 
                {
                        main( me, file + "/" );    // ������Ŀ¼
                }
                else if( file[<4..<1] == ".htm" ) 
                {
                        html = read_file(file);

                        if( !( p = strstr(html, BEGIN_MARK, 1) ) ) 
                        {
                                tell_user(me, "%s ����ʼ���", file);
                                continue;
                        }
                        if( !( p2 = strstr(html, END_MARK, 1) ) ) 
                        {
                                tell_user(me, "%s �޽������", file);
                                continue;
                        }

                        result = html2 + html[p + strlen(BEGIN_MARK) + 1..p2-1] + html3;

                        rm(file);    // ������ļ�(WINDOWS)
                        write_file(file, result);
                }
        }

        return 1;
}
