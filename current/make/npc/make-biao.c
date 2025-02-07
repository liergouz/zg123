
#define CPP_FILE        __DIR__ "biao.cc"
#define TEXT_FILE       __DIR__ "biao.txt"
#define LIST_LOG        "list.txt"
#define LIST_LOG_2      "list2.txt"

// �����������
int main( object me, string arg )
{
        string cpp, *line, file, name, city, xy;
        int id, pic, z, x, y, d, flag, i, size;

        cpp = read_file( CPP_FILE );
        line = explode( read_file( TEXT_FILE ), "\n" );

        log_file( LIST_LOG, "# ��������\n" );
        log_file( LIST_LOG_2, "// ��������\n" );

        size = sizeof(line);
        for( i = 0; i < size; i ++ ) 
        {
                if( line[i][0] == '#' || line[i] == "" ) continue;
                if( sscanf( line[i], "%d %s %d %s %d %s", id, name, pic, city, z, xy ) )
                {
                        file = sprintf("make/%04d.c", id );
                        rm( LOG_DIR + file );    // ������ļ�(WINDOWS)

                        xy = replace_string(xy, "��", ",");
                        if( sscanf( xy, "%d,%d,%d", x, y, d ) )
                                log_file( LIST_LOG, sprintf("%d-%d,%d,%d:/npc/80/%04d\n", z, x, y, d, id ) );
                        else    tell_user(me, "ERR: %04d ����: %s", id, xy);

                        flag = ( city == "����" ) ? 1 : 0;

                        if( !flag ) log_file( LIST_LOG_2, sprintf("        \"%s%s\" : \"%d-%d,%d\",\n", city, name, z, x, y) );

                        log_file( file, sprintf( cpp, pic, name, city,
                                flag ? "  " : "/*", flag ? "  " : "*/", 
                                flag ? "  " : "//", flag ? "//" : "  ",
                                flag ? "  " : "//", flag ? "  " : "//" ) );
                        file = LOG_DIR + file;  file->do_nothing();
                }
        }

        tell_user( me, "��鿴 /log/make/ �ļ��� /log/list.txt ����㣬list2.txt �б�(�����)��" );

        return 1;       
}
