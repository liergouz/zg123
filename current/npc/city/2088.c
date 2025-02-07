
// �Զ����ɣ�/make/npc/make8088

#include <npc.h>
#include <task.h>
#include <ansi.h>

#define JOB_TRADER_D    "/inh/job/trader"

inherit OFFICER;
inherit "/inh/npc/trader";
int is_self_look() { return 1;}

void reset();
void do_good( string arg );

// ��������ȡ��������
int get_char_picid() { return 5401; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("��������");
	set_real_name("����");
        set_city_name("����");

        set_2( "talk", ([
                "good"          : (: do_good :),
                "welcome"	: (: do_welcome :),
        ]) );
//        set("level",79);
//        set("legend",({32*26+10}));
 	set("mpLegend",([75:({32*26+10})]));
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
                "01" : "/item/99/9921",
                "02" : "/item/99/9922",
                "03" : "/item/99/9923",
        ]) );
        set_2( "list", ([
                "01" : 600,
                "02" : 500,
                "03" : 100,
        ]) );
}

void do_look( object who )
{
	string tmp="";
	object me = this_object();
	
	if ( who->get_level() >= 75 && !who->get_legend(TASK_26,10) )
		tmp += sprintf(ESC HIY "���˿���\ntalk %x# welcome.1\n",getoid(me));

	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_normal_word(me) + "\n"ESC"����\ntalk %x# welcome.99\n",get_name(),getoid(me)) +
		tmp +
		ESC"�뿪");
	else
		JOB_TRADER_D->do_look( who, me ); 
	
}
void do_good( string arg ) { JOB_TRADER_D->do_good( this_player(), this_object(), arg ); }

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,p;
        object who,item;     
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_level() >= 75 && !who->get_legend(TASK_26,10) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����һ��ֶ�ӽ���Ϊ��������Ϊ����һ����һ����ɫ�����ˡ������ڼ�����֮ǰ��Ϊ���������ӵ���̤�������ʱ��������һ���������������˴�٣�������Ϊ��Ǯ�Ʊ�����һ�գ���Ϊ�����ӻ��������˲��̵�ɱ���ˡ��Ӵ���Ϊһֱ�����ѻ��������Ծ�����Ҳ������ҵ�ֶ�ӱ������Ƿϣ��������������ڲ�����������������ȶ������Ƽ�ʹ�ǹٸ�Ҳ�����κ����������Ҳ���������ֶ�ӵ�����������ôԩ����������д��״ֽ�������Ұ�������������ʷ֣���ɡ����������ҲҪΪ�ҵ�ֶ���ֻ�һ��������\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
	       	break;
        case 2 :
        	if ( who->get_level() >= 75 && !who->get_legend(TASK_26,10) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		item = new("item/98/0123");
        		if ( !item )
        			return ;
        		p = item->move(who,-1);
        		if ( !p )
        		{
        			destruct(item);
        			send_user(who,"%c%s",'!', "��Я������Ʒ̫����");
        			return;
        		}
        		item->add_to_user(p);
        		who->set_legend(TASK_26,10);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_HANGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,31,"���˿���" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���˿���");
        	}
        	break;
    
        case 99:
        	JOB_TRADER_D->do_look( who, me ); 
        	break;
        }
}