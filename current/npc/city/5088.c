
// �Զ����ɣ�/make/npc/make8088

#include <npc.h>

#define JOB_TRADER_D    "/inh/job/trader"

int is_self_look() { return 1;}
inherit OFFICER;
inherit "/inh/npc/trader";

void reset();
void do_good( string arg );

// ��������ȡ��������
int get_char_picid() { return 5401; }

// ���������촦��
void create()
{
        set_name("�ع�����");
	set_real_name("κȽ");
        set_city_name("�ع�");

        set_2( "talk", ([
                "good"          : (: do_good :),
        ]) );
        reset();

        setup();
}

// ��������λ����
void reset()
{
	object me = this_object();
	me->set("reset_time", time());
        set_buy_rate( random(1001) );
        set_sell_rate( random(1001) );

        set_2( "good", ([
                "01" : "/item/99/9951",
                "02" : "/item/99/9952",
                "03" : "/item/99/9953",
        ]) );
        set_2( "list", ([
                "01" : 100,
                "02" : 30,
                "03" : 20,
        ]) );
}

void do_look( object who ) { JOB_TRADER_D->do_look( who, this_object() ); }

void do_good( string arg ) { JOB_TRADER_D->do_good( this_player(), this_object(), arg ); }
