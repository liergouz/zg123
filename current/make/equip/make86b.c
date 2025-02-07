
#define CPP_FILE        __DIR__ "86b.cc"
#define HTM_FILE        __DIR__ "86b.htm"
#define TEXT_FILE       __DIR__ "86b.txt"
#define LIST_LOG        "list.txt"

// �����������
int main( object me, string arg )
{
        string cpp, htm, *line, file, name, unit;
        int id, pic1, pic2, level, value, lasting, cp, pp;
        int i, size;

        cpp = read_file( CPP_FILE );
        htm = read_file( HTM_FILE );
        line = explode( read_file( TEXT_FILE ), "\n" );

                        log_file( LIST_LOG, "# ��������\n" );

        size = sizeof(line);
        for( i = 0; i < size; i ++ ) 
        {
                if( line[i][0] == '#' || line[i] == "" ) continue;
                if( sscanf( line[i], "%d %s %d %d %s %d %d %d %d%% %d", 
                        id, name, pic1, pic2, unit, level, value, lasting, cp, pp ) )
                {
                        file = sprintf("make/%04d.c", id );
                        rm( LOG_DIR + file );    // ������ļ�(WINDOWS)

                        lasting = lasting / 100 * 100 + 99;
                        log_file( file, sprintf( cpp, name, pic1, pic2, unit, level, value, lasting, cp, pp, name ) );

                        log_file( LIST_LOG, sprintf( htm, name, level, "�С�Ů", "��", pp, cp, lasting / 100, lasting / 100, value ) );
                }
        }

        tell_user( me, "��鿴 /log/make/ �µ��ļ���" );

        return 1;       
}
