
#define LIST_LOG        "str.txt"
#define FINAL_D		"/quest/final"

// �����������
int main( object me, string arg )
{
	string str = "";
	int i,size;
	string *p_str = ({});
	
	p_str += ({FINAL_D->file_final_lv(24)});
	p_str += ({FINAL_D->file_final_lv2(24,44)});
	p_str += ({FINAL_D->file_final_fam_lv("�һ�Դ",24)});
	p_str += ({FINAL_D->file_final_fam_lv2("��ɽ",24,44)});
	p_str += ({FINAL_D->file_final_type_lv(69,24)});
	p_str += ({FINAL_D->file_final_type_lv2(62,24,44)});
	p_str += ({FINAL_D->file_final_fam_type_lv("�һ�Դ",69,30)});
	p_str += ({FINAL_D->file_final_fam_type_lv2("�һ�Դ",69,30,90)});
	
	p_str += ({FINAL_D->file_final_fam_type_lv("�һ�Դ",70,85)});
	p_str += ({FINAL_D->file_final_fam_type_lv2("�һ�Դ",70,30,90)});
	
	p_str += ({FINAL_D->file_final("",-1,24,-1)});
	p_str += ({FINAL_D->file_final("",-1,24,44)});
	p_str += ({FINAL_D->file_final("�һ�Դ",-1,24,-1)});
	p_str += ({FINAL_D->file_final("��ɽ",-1,24,44)});
	p_str += ({FINAL_D->file_final("",69,24,-1)});
	p_str += ({FINAL_D->file_final("",62,24,44)});
	p_str += ({FINAL_D->file_final("�һ�Դ",69,30,-1)});
	p_str += ({FINAL_D->file_final("�һ�Դ",69,30,90)});
	
	p_str += ({FINAL_D->file_final("�һ�Դ",70,85,-1)});
	p_str += ({FINAL_D->file_final("�һ�Դ",70,30,90)});
	

	size = sizeof(p_str);
	for(i=0;i<size;i++)
	{
		str += p_str[i]+"\n";
	}
	log_file( LIST_LOG, str );
        tell_user( me, "��鿴 /log/str.txt" );

        return 1;
}