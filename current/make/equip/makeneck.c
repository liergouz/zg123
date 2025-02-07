
#define CPP_FILE        __DIR__ "neck.cc"
#define HTM_FILE        __DIR__ "60b.htm"
#define TEXT_FILE       __DIR__ "neck.txt"
#define LIST_LOG        "list.txt"

// �����������
int main( object me, string arg )
{
        string cpp, htm, *line, file, name, type, fam, type2;
        int id, num, pic, level, value, lasting, cp, pp, armor;
        int i, size, olddir, dir, oldid, famtype;

        cpp = read_file( CPP_FILE );
        htm = read_file( HTM_FILE );
        line = explode( read_file( TEXT_FILE ), "\n" );

                        log_file( LIST_LOG, "# �·�\n\n" );

        size = sizeof(line);
        olddir = 0; oldid = 0;
        for( i = 0; i < size; i ++ ) 
        {
                if( line[i][0] == '#' || line[i] == "" ) continue;
                if( sscanf( line[i], "%s %d %s %d %d %d %d %d", 
                        name, pic,  fam, level, value, lasting, cp, pp ) )
                {
                	dir = 86;
                	switch(fam)
                	{
                	default:
                		famtype = 8;
                		break;
                	case "�һ�Դ":
                		famtype = 1;
                		break;
                	case "��ɽ":
                		famtype = 2;
                		break;
                	case "������":
                		famtype = 3;
                		break;
                	case "����":
                		famtype = 4;
                		break;
                	case "éɽ":
                		famtype = 5;
                		break;
                	case "����ɽ":
                		famtype = 6;
                		break;
                	case "������":
                		famtype = 7;
                		break;
                	}
                	if (olddir!=dir)
                	{
                		mkdir(sprintf(LOG_DIR+"make/%d", dir));
                		olddir = dir;
                	}
                	if (fam=="������") id = level;
                	else id = 1000*famtype+ level;
                	if (id==0) id = 1;
                	if (oldid==id) id = oldid + 1;
                	oldid = id;
                        file = sprintf("make/%02d/%04d.c", dir, id );
                        rm( LOG_DIR + file );    // ������ļ�(WINDOWS)
                        lasting = lasting / 100 * 100 + 99;
                        log_file( file, sprintf( cpp, famtype, name, pic, pic, level, value, lasting, cp, pp, name ) );
                        file = LOG_DIR + file;  file->do_nothing();                        
                }
        }

        tell_user( me, "��鿴 /log/make/ �µ��ļ���" );

        return 1;       
}
