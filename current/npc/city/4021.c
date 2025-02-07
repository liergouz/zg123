
// �Զ����ɣ�/make/npc/make8020
#include <ansi.h>
#include <npc.h>
#include <task.h>

#define INTERIOR_D      "/inh/city/interior"

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 0452; }
void do_welcome(string arg);

// ������ʦ��ʶ��
int is_master() { return 1; }

// ������ʦ��ʶ��(���ͷ)
int is_basic_master() { return 2; }

int is_self_look() { return 1; }

// ������С��ʶ��
int is_seller() { return 1; }

// ���������촦��
void create()
{
        set_name("κ������");
        set_real_name("����21~40");
        set_city_name("κ��");
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ])); 
//	set("level",110);
//	set("legend",({32*39+5}));
	set("mpLegend",([105:({32*39+5,}),]));
	set_skill(0630, 39);
        set_2( "good", ([
                "01" : "/item/product/63007",
                "02" : "/item/product/63008",
                "03" : "/item/product/63009",
                "04" : "/item/product/63010",
                "05" : "/item/product/63011",
                "06" : "/item/product/63012",
                "07" : "/item/product/63013",
                "08" : "/item/product/63014",                
        ]) );		
        setup();
}

void do_look( object who )
{
	string tmp="";
	object me = this_object();
	if ( who->get_level() >= 105 && !who->get_legend(TASK_39,5) )
		tmp += sprintf(ESC HIY "���ɵĹ���\ntalk %x# welcome.1\n",getoid(me));

	tmp += sprintf(ESC"ѧϰ�����\nlearn ? %s\n", me->get_char_id());
	tmp += sprintf(ESC"�����������ܵȼ�21-40�����䷽\nlist %s\n", me->get_char_id());
	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) + "\n",get_name(),getoid(me)) +
		tmp +
		ESC"�뿪");
	else
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) ,get_name()));
	
}

int accept_object( object who, object obj ) { return INTERIOR_D->accept_object_2( who, this_object(), obj, 2 ); }

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,i,size,p,amount;
        object who,item, *inv;     
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
	        case 1:
			if ( who->get_level() >= 105 && !who->get_legend(TASK_39,5) )
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ǰЩ������ܼ����Ҹ�����С����һ�������䣬���ҽ���Ҫ�򵥺��ã�ʽ��Ҳ����Ҫ̫����������Ϊ����С����һ�������ص�Ů�ӡ�\n    �����˺�Щ���Ӳ����ã������Ϻõ�ľ�ģ������в�ʧ���Σ�����С��һ����ϲ���ġ�\n    ������Ұ���������佻����ܼң��������ʱ��Ļ��Ҿ��Լ�ȥ�ˣ�˵ʵ�����һ�ͦ�������λ���ڲ�ͬ��С�㡣\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
	        	break; 
	        case 2:
	        	if ( who->get_level() >= 105 && !who->get_legend(TASK_39,5) )
	        	{
	        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
	        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
	        			return ; 
				TASK_LEGEND_D->give_item(who,"item/98/0185",1); 
	        		who->set_legend(TASK_39,5);
				send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_WEIGUO,"κ��" );
				send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,68,"���ɵĹ���" );
				send_user( who, "%c%s", '!', "�õ����� "HIY"���ɵĹ���");
	        	}
	        	break;         	
        }
}