
#define CPP_FILE        __DIR__ "72.cc"
#define HTM_FILE        __DIR__ "72.htm"
#define TEXT_FILE       __DIR__ "72.txt"
#define LIST_LOG        "list.txt"

// �����������
int main( object me, string arg )
{
        string cpp, htm, *line, file, name, unit;
        int id, num, pic, level, value, lasting, ap, dp, cp, sp;
        int i, size;

        cpp = read_file( CPP_FILE );
        htm = read_file( HTM_FILE );
        line = explode( read_file( TEXT_FILE ), "\n" );

                        log_file( LIST_LOG, "# ��\n\n" );

        size = sizeof(line);
        for( i = 0; i < size; i ++ ) 
        {
                if( line[i][0] == '#' || line[i] == "" ) continue;
                if( sscanf( line[i], "%d %d %s %d %d %d %d %d %d %d %d", 
                        id, num, name, pic, level, value, lasting, ap, dp, cp, sp ) )
                {
                        file = sprintf("make/%04d.c", id );
                        rm( LOG_DIR + file );    // ������ļ�(WINDOWS)

                        lasting = lasting / 100 * 100 + 99;
                        log_file( file, sprintf( cpp, name, pic, pic, level, value, lasting, ap, dp, cp, sp, num ) );
                        file = LOG_DIR + file;  file->do_nothing();                        
                }
        }

        tell_user( me, "��鿴 /log/make/ �µ��ļ���" );

        return 1;       
}
