
// �Զ����ɣ�/make/npc/make8020

#include <npc.h>

#define INTERIOR_D      "/inh/city/interior"

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return %04d; }

// ���������촦��
void create()
{
        set_name("%s");
        set_city_name("%s");

        setup();
}

// �������Ի�����
void do_look( object who )
{
        more_look_menu( who, sprintf( "%%s��\n    %%s\n", get_name(), "/quest/word"->get_country_word(this_object()) ) );
}

int accept_object( object who, object obj ) { return INTERIOR_D->accept_object_2( who, this_object(), obj, %d ); }
