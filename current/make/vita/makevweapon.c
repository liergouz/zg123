
#define CPP_FILE        __DIR__ "vweapon.cc"
#define HTM_FILE        __DIR__ "std.htm"
#define TEXT_FILE       __DIR__ "vweapon.txt"
#define LIST_LOG        "list.txt"

// �����������
int main( object me, string arg )
{
        string cpp, htm, *line, file, name, type, fam, type2;
        int id, num, pic, level, showlevel, value, lasting, ap, dp, cp, sp;
        int i, size, olddir, dir, oldid, famtype, final;

        cpp = read_file( CPP_FILE );
        htm = read_file( HTM_FILE );
        line = explode( read_file( TEXT_FILE ), "\n" );

        size = sizeof(line);
        olddir = 0; oldid = 0;
        for( i = 0; i < size; i ++ ) 
        {
                if( line[i][0] == '#' || line[i] == "" ) continue;
                if( sscanf( line[i], "%s %d %s %d %s %d %d %d %d %d %d %d", 
                        type, final, name, pic, fam, level, value, lasting, ap, dp, cp, sp ) )
                {
                	showlevel = level / 10 + 1;
                	switch(type)
                	{
                	case "��":
                		dir = 72;
                		type2 = "����";
                		type = "BLADE";
                		break;
                	case "ǹ":
                		dir = 74;
                		type2 = "ǹ��";
                		type = "SPEAR";
                		break;
                	case "��":
                		dir=76;
                		type2 = "����";
                		type = "SWORD";
                		break;
                	case "��":
                		dir = 75;
                		type2 = "����";
                		type = "STICK";
                		break;
                	case "ȭ��":
                		dir = 70;
                		type2 = "ȭ��";
                		type = "UNARMED";
                		break;
                	case "����":
                		dir = 71;
                		type2 = "����";
                		type = "THROWING";
                		break;
                	}
                	switch(fam)
                	{
                	default:
                		// �������������ɿ���װ��
                		famtype = 9;
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
                	else id = 1000+ level;
                	oldid = id;
                        file = sprintf("make/%02d/%04d.c", dir, id );
                        rm( LOG_DIR + file );    // ������ļ�(WINDOWS)

                        lasting = lasting / 100 * 100 + 99;
                        log_file( file, sprintf( cpp, (dir==71)?"MISSILE":"WEAPON", famtype, final, name, pic, pic, level, value, lasting, ap, dp, cp, sp, type, showlevel, type2 ) );
                        file = LOG_DIR + file;  file->do_nothing();                        
                        log_file( LIST_LOG, sprintf("\"%s\": \"\\\"/item/final/%02d/%04d\\\"\", \n", name, dir, id) );
                }
        }

        tell_user( me, "��鿴 /log/make/ �µ��ļ���" );

        return 1;       
}
