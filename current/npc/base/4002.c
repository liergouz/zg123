
// �Զ����ɣ�/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

// ���Լ���do_look����
int is_self_look() { return 1; }
// ������С��ʶ��
int is_seller() { return 5; }

// ��������ȡ��������
int get_char_picid() { return 5402; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("�ӻ����ϰ�");
	set_real_name("����");
        set_city_name("κ��");

        set_2( "good", ([
                "01" : "/item/std/0401",
                "02" : "/item/std/0407",
                "04" : "/item/std/0409",
                "05" : "/item/std/0413",
                "06" : "/item/std/0591",
                "07" : "/item/32/3231",
                "08" : "/item/98/9871",
                "09" : "/item/std/9808",
                "10" : "/item/std/9819",
                "11" : "/item/std/9820",
		"12" : "/item/stuff/0505",
		"13" : "/item/stuff/0506",       
		"14" : "/item/49/4900",  	 
		"15" : "/item/std/0410",     
		"16" : "/item/08/0010",
		"17" : "/item/08/0011",
		"18" : "/item/08/0012", 
		"19" : "/item/44/4403",
		"20" : "/item/44/4406",
		"21" : "/item/stuff/0507",
        ]) );
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));
//	set("level",22);
//	set("legend",({32*5+16}));
 	set("mpLegend",([20:({32*5+16}),]));
 	set("mpLegend2",([20:({32*5+18}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	object me = this_object();
	string result;
	"/quest/help"->send_help_tips(who, 41);
	result = sprintf("%s��\n    "+"/quest/word"->get_normal_word(me)+"\n", me->get_name() );
	if ( (who->get_level() >= 20 && !who->get_legend(TASK_05, 16)) || (who->get_legend(TASK_05, 16) && !who->get_legend(TASK_05, 18)) )
	{
		result = result + sprintf( ESC HIY "Ӣ�۵�ĥ��\ntalk %x# welcome.1\n", getoid(me) );
	}	

	result = result + sprintf( ESC "����\nlist %x#\n" ESC "��ֻ����㿴��\nCLOSE\n", getoid(me) ) ;        	
	send_user( who, "%c%s", ':', result );

}
void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,p;
        object who,item,obj;  
        string cmd1;
           
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_level() >= 20 && !who->get_legend(TASK_05,16)  )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �������ľ����ΪӢ�ۣ���־���ǲ������ǵÿ�����û���Ǹ�������\n    ����֤�����ҿ������Ǹ������𣿺ðɣ���ȥ�������ӣ��԰�����ֻ����ħ���ҵþ����㣬������пɱ�Ӳ�ţ���ֻ����ħ���Ѳ�����һ����ʲô�����ҿɸ�����������Ρ�\n    ��Ҫȥ�Ļ��ͳ��Ŵ����ǵ����������ߣ�һ�����������ܿ�����ֻ����ħ���ǵ�ҪС�ġ�\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_05,16) && !who->get_legend(TASK_05,17) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ΪӢ�۲������������ô�򵥰��������㻹�ö�ĥ��ĥ����\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_05,17) && !who->get_legend(TASK_05,18) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    СС��;��Ѿ��߱���ΪӢ�۵�Ǳ�ʣ�ǰ;���ް���\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
			
        	break;
        case 2:
        	if ( who->get_level() >= 20 && !who->get_legend(TASK_05,16)  )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_05,16);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_WEIGUO,"κ��" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,14,"Ӣ�۵�ĥ��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"Ӣ�۵�ĥ��");
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_05,17) && !who->get_legend(TASK_05,18) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->task_finish(who);
        		TASK_LEGEND_D->give_item(who,"item/product/64005",1);
			who->set_legend(TASK_05,18);
			who->add_exp(1100);
			who->add_potential(70);
			who->add_cash(1200);
			send_user(who,"%c%s",';',"Ӣ�۵�ĥ�� ���� 1100 Ǳ�� 70 ��Ǯ 1200 �����װͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,14,"" );
        	}
        	break;
        }
}
