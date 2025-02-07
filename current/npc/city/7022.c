
// �Զ����ɣ�/make/npc/make8020
#include <ansi.h>
#include <npc.h>

#define INTERIOR_D      "/inh/city/interior"

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 0452; }

// ������ʦ��ʶ��
int is_master() { return 1; }

// ������ʦ��ʶ��(���ͷ)
int is_basic_master() { return 2; }

// ���������촦��
void create()
{
        set_name("�������");
        set_city_name("���");
	set_skill(0670, 80);
        setup();
}

void do_look( object who )
{
        object me = this_object();
        send_user( who, "%c%c%w%s", ':', 3, 0451, 
        	sprintf("%s��\n    %s\n" 
	       	ESC "ѧϰ����\nlearn ? %s\n" 
        	ESC "�ر�\nCLOSE\n", 
        	me->get_name(), "/quest/word"->get_country_word(this_object()), me->get_char_id() ) );
}

int accept_object( object who, object obj ) { return INTERIOR_D->accept_object_2( who, this_object(), obj, 4 ); }
