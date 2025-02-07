
#define CPP_FILE        __DIR__ "8020.cc"
#define TEXT_FILE       __DIR__ "8020.txt"
#define LIST_LOG        "list.txt"

// �����������
int main( object me, string arg )
{
        string cpp, *line, file, name, xy, city;
        int id, pic, z, x, y, d, flag, i, size;

        cpp = read_file( CPP_FILE );
        line = explode( read_file( TEXT_FILE ), "\n" );

        log_file( LIST_LOG, "# ����\n" );

        size = sizeof(line);
        for( i = 0; i < size; i ++ ) 
        {
                if( line[i][0] == '#' || line[i] == "" ) continue;
                if( sscanf( line[i], "%d %s %d %s %d %s %d", id, name, pic, city, z, xy, flag ) )
                {
                        file = sprintf("make/%04d.c", id );
                        rm( LOG_DIR + file );    // ������ļ�(WINDOWS)

                        xy = replace_string(xy, "��", ",");
                        if( sscanf( xy, "%d,%d,%d", x, y, d ) )
                                log_file( LIST_LOG, sprintf("%d-%d,%d,%d:/npc/city/%04d\n", z, x, y, d, id ) );
                        else    tell_user(me, "ERR: %04d ����: %s", id, xy);

                        log_file( file, sprintf( cpp, pic, name, city, flag ) );
                        file = LOG_DIR + file;  file->do_nothing();
                }
        }

        tell_user( me, "��鿴 /log/make/ �µ��ļ��� /log/list.txt ������㡣" );

        return 1;       
}
