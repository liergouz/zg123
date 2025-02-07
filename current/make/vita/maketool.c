
#define CPP_FILE        __DIR__ "tool.cc"
#define HTM_FILE        __DIR__ "std.htm"
#define TEXT_FILE       __DIR__ "tool.txt"
#define LIST_LOG        "list.txt"

// �����������
int main( object me, string arg )
{
        string cpp, htm, *line, file, name, desc, type, color;
        int id, pic1, pic2, combined, value, level, lasting, level2;
        int i, size, iColor;

        cpp = read_file( CPP_FILE );
        htm = read_file( HTM_FILE );
        line = explode( read_file( TEXT_FILE ), "\n" );

                        log_file( LIST_LOG, "<!-- ҩ�� -->\n\n" );

        size = sizeof(line);
        for( i = 0; i < size; i ++ ) 
        {
                if( line[i][0] == '#' || line[i] == "" ) continue;
                if( sscanf( line[i], "%d %s %d %s %s %d %d %d %s", 
                        id, name, pic1, color, desc, level, lasting, value, type  ) )
                {
                        file = sprintf("make/%04d.c", id );
                        rm( LOG_DIR + file );    // ������ļ�(WINDOWS)
			switch(type)
			{
			case "����":
				type = "ITEM_TYPE_2_HAMMER";
				break;
			case "����":
				type = "ITEM_TYPE_2_STOVE";
				break;
			case "�÷�":
				type = "ITEM_TYPE_2_NEEDLE";
				break;
			case "ʯ��":
				type = "ITEM_TYPE_2_GRAVER";
				break;
			case "�ڿ�":
				type = "ITEM_TYPE_2_DIG";
				break;
			case "�ɼ�":
				type = "ITEM_TYPE_2_REAPHOOK";
				break;																				
			}
			switch(color)
			{
			case "��ɫ":
				iColor = 0;
				break;
			case "��ɫ":
				iColor = 1;
				break;				
				
			}
			lasting = lasting*100+99;
                        log_file( file, sprintf( cpp, id, type, iColor, name, pic1, pic1, value, lasting, lasting, level, desc ) );
                        file = LOG_DIR + file;  file->do_nothing();

                        log_file( LIST_LOG, sprintf( htm, name, value, file->get_desc() ) );
                }
        }

        tell_user( me, "��鿴 /log/make/ �µ��ļ���" );

        return 1;       
}
