
#define TEXT_FILE       __DIR__ "74.txt"
#define LIST_LOG        "list.txt"

// �����������
int main( object me, string arg )
{
        int i, size,id,iLev,type,j;
        string cpp,*line,tmp1,name,level,desc,file,tmp;

        line = explode( read_file( TEXT_FILE ), "\n" );

	log_file( LIST_LOG, "# ���﷨��DATA\n" );

        size = sizeof(line);
        file = "make/beastskill.txt";
	rm( LOG_DIR + file );    // ������ļ�(WINDOWS)
        log_file(file,"mapping mpBeastSkill = ([ \n");
        tmp = "		";
        for( i = 0; i < size; i ++ ) 
        {
                if( line[i][0] == '#' || line[i] == "" ) continue;
                if( sscanf( line[i], "%s %d %s %s %s", tmp1,id,name,level,desc) == 5 )
                {
                	if ( tmp1 == "����" )
                		type = 1;
                	else 
                		type = 0;
                	if ( level == "�߼�" )
                		iLev = 1;
                	else
                		iLev = 0;
                	id = 74*1000+id ;

                       tmp += sprintf("\"%s\" : %d, ",name,id);
                       if ( j++ >= 10 )
                       	{
                       		tmp += "\n		";	
                       		j = 0;
                       	}

                }
        }
        log_file(file,tmp+"\n		]); \n");

        tell_user( me, "��鿴 /log/make/ �µ��ļ���" );

        return 1;       
}
