#include <ansi.h>
#include <public.h>

// �������ղ�Ʒ�ļ��б�
string *FileTable = ({
        "/item/97/9701", 
        "/item/97/9702", 
        "/item/97/9703", 
        "/item/97/9704", 
        "/item/97/9705", 
        "/item/97/9706", 
        "/item/97/9707", 
        "/item/97/9708", 
        "/item/97/9709", 
        "/item/97/9710", 
        "/item/97/9711", 
        "/item/97/9712", 
        "/item/97/9713", 
        "/item/97/9714", 
        "/item/97/9715", 
        "/item/97/9716", 
        "/item/97/9717", 
        "/item/97/9720", 
        "/item/97/9721", 
        "/item/97/9722", 
        "/item/97/9723", 
        "/item/97/9724", 
        "/item/97/9725", 
        "/item/97/9726", 
        "/item/97/9727", 
        "/item/97/9728", 
        "/item/97/9729", 
        "/item/97/9730", 
        "/item/97/9731", 
        "/item/97/9732", 
        "/item/97/9733", 
        "/item/97/9750", 
        "/item/97/9751", 
        "/item/97/9752", 
        "/item/97/9753", 
        "/item/97/9754", 
        "/item/97/9755", 
        "/item/97/9770", 
        "/item/97/9771", 

});

int sizeof_file = sizeof(FileTable);

// �������ղ�Ʒ�����б�

string *NameTable = ({
        "��ѧ", 
        "��ӹ", 
        "����", 
        "����", 
        "ʫ��", 
        "����", 
        "���", 
        "����", 
        "����", 
        "��ԯ����", 
        "ʮ�޼�", 
        "����", 
        "�Ÿ�", 
        "����", 
        "�ž���", 
        "���", 
        "�����ͼ", 
        "�ļ�ͼ����", 
        "�ļ�ͼ����", 
        "�ļ�ͼ����", 
        "�ļ�ͼ����", 
        "д�⻨�ݡ�÷", 
        "д�⻨�ݡ���", 
        "д�⻨�ݡ���", 
        "д�⻨�ݡ���", 
        "������ɫͼ", 
        "��ˮԧ��ͼ", 
        "��ɽ����ͼ", 
        "�ٷﳯ��ͼ", 
        "��Ůɢ��ͼ", 
        "����ͼ", 
        "��������", 
        "��������", 
        "��������", 
        "ȸ������", 
        "ԧ������", 
        "�����", 
        "�໨������", 
        "��ͭ�ž�",         
});

int sizeof_name = sizeof(NameTable);

// ��������ȡ�ղ�Ʒ�ļ�
string get_collect_file() { return FileTable[ random(sizeof_file) ]; }

// ��������ȡ�ղ�Ʒ����
string get_collect_name() { return NameTable[ random(sizeof_name) ]; }
//��������do_look
void do_look( object who,object npc)
{
	string cmd="";
	if ( who->get_save_2("qixi.flag") == 3 && time()<"sys/party/qixi"->get_qixi_time())
		cmd=sprintf(ESC "��Ѱ��ĸ����\ntalk %x# qixi.1\n",getoid(npc));
	if ( time()<"sys/party/qixi"->get_qixi_time() &&( who->get_save_2("qixi.flag") == 8 || who->get_save_2("qixi.flag") == 9 || who->get_save_2("qixi.flag") == 10 || who->get_save_2("qixi.flag") == 11 ) )
		cmd=sprintf(ESC "��Ϧ�����Ե��2��\ntalk %x# qixi.1\n",getoid(npc));
	if ( sizeof(npc->get_2("good")) != 0 )
	{
		if ( who->get_save_2("mastertask.type") != 7 || who->get_save_2("mastertask.status") == 99)
		        send_user( who, "%c%c%w%s", ':', 3, npc->get_char_picid(), 
		                sprintf("%s��\n    �ٺ٣�ֻ����Ե�˲����ҵ��ң���Ȼ���ܹ���ô����������������������ҵ���Ե�ˣ������ϵĶ������㾡�����ɣ��Դ���Ե�ˣ��ҴӲ����ġ�"+"/quest/word"->get_normal_word(npc)+"\n"
		                        ESC "����\nlist %x#\n"
		                        ESC "�뿪\nCLOSE\n", npc->get_name(), getoid(npc) ) +cmd);   
		else
		        send_user( who, "%c%c%w%s", ':', 3, npc->get_char_picid(), 
		                sprintf("%s��\n    �ٺ٣�ֻ����Ե�˲����ҵ��ң���Ȼ���ܹ���ô����������������������ҵ���Ե�ˣ������ϵĶ������㾡�����ɣ��Դ���Ե�ˣ��ҴӲ����ġ�"+"/quest/word"->get_normal_word(npc)+"\n"
		                        ESC "�����ҩ\ntalk %x# accept_task.1\n"
		                        ESC "����\nlist %x#\n"
		                        ESC "�뿪\nCLOSE\n", npc->get_name(), getoid(npc),getoid(npc) ) );   
	}
	else
	{
		if ( who->get_save_2("mastertask.type") != 7 || who->get_save_2("mastertask.status") == 99)
		        send_user( who, "%c%c%w%s", ':', 3, npc->get_char_picid(), 
		                sprintf("%s��\n    ������������һ�����ո��ҵ����һ���ղ�Ʒ�Ѿ������������ˣ��������ǵ�Ե�ֻ�δ�������ļ��������ȴ��ɣ�����һ��Ե�ֻᵽ���ġ�"+"/quest/word"->get_normal_word(npc)+"\n"	
		                        ESC "�뿪\nCLOSE\n", npc->get_name(), getoid(npc) ) +cmd);   
		else
		        send_user( who, "%c%c%w%s", ':', 3, npc->get_char_picid(), 
		                sprintf("%s��\n    ������������һ�����ո��ҵ����һ���ղ�Ʒ�Ѿ������������ˣ��������ǵ�Ե�ֻ�δ�������ļ��������ȴ��ɣ�����һ��Ե�ֻᵽ���ġ�"+"/quest/word"->get_normal_word(npc)+"\n"
		                        ESC "�����ҩ\ntalk %x# accept_task.1\n"
		                        ESC "�뿪\nCLOSE\n", npc->get_name(), getoid(npc),getoid(npc) ) );   
	}		
		
}
