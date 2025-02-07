
// �Զ����ɣ�/make/npc/make0015

#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <equip.h>

inherit OFFICER;

// ������С��ʶ��
int is_seller() { return 1; }

// ���Լ���do_look����
int is_self_look() { return 1; }

void do_talk_exchange();

void do_info();
void do_exchange(string sArg);
void do_inputx(string sArg);
void do_welcome(string sArg);

// ��������ȡ��������
int get_char_picid() { return 5415; }

// ���������촦��
void create()
{
        set_name("�Ƶ��ϰ�");
	set_real_name("����");

      	set_2( "talk", ([
                "info"  : (: do_info :),
                "do_exchange" : (: do_exchange :),
                "inputx"	: (: do_inputx :),   
                "exchange" : (: do_talk_exchange :),             	
                "welcome" : (: do_welcome :),             	
        ]));    
        set_2( "good", ([
                "01" : "/item/31/3150",
                "02" : "/item/31/3151",
                "03" : "/item/31/3152",
                "04" : "/item/32/3280",
                "05" : "/item/32/3281",
                "06" : "/item/32/3282",
                "07" : "/item/32/3283",
                "08" : "/item/32/3284",
                "09" : "/item/32/3285",
                "10" : "/item/stuff/0165",
		"11" : "/item/stuff/0166",
		"12" : "/item/stuff/0167",
		"13" : "/item/stuff/0168",                
		"14" : "/item/stuff/0213",
		"15" : "/item/stuff/0214",
		"16" : "/item/stuff/0219",
		"17" : "/item/stuff/0220",
		"18" : "/item/stuff/0221",
		"19" : "/item/stuff/0222",                
		"20" : "/item/stuff/0223",
		"21" : "/item/stuff/0224",	
		"22" : "/item/stuff/0159",	
		"23" : "/item/32/3204",
        ]) );
//	set("level",30);
//	set("legend",({32*7+25}));
 	set("mpLegend",([30:({32*7+25,32*9+1}),]));
 	set("mpLegend2",([30:({32*7+27,32*9+3}),]));
        setup();
}

void do_talk_exchange()
{
	TASK_COLLECT_D->do_talk_exchange( this_player(), this_object(), 6015 );
}

// �������Ի�����
void do_look( object who )
{
	object item;
	object me = this_object(), map;
        int id = getoid(me);
	string tmp;
	"/quest/help"->send_help_tips(who, 53);
	tmp = "";
        tmp += sprintf(ESC"����ʳ��\nlist %x#\n", id);
//        tmp += sprintf(ESC"��ȡʳ��\ntalk %x# exchange\n",id);
        tmp += sprintf(ESC"���䴫��\ntalk %x# info\n", id);
        if ( ( who->get_level() >= 30 && !who->get_legend(TASK_07,25) ) || ( who->get_legend(TASK_07,25) && !who->get_legend(TASK_07,27) ) )
		tmp += sprintf(ESC HIY "��Ƭ��ë\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( ( who->get_legend(TASK_07,27) && !who->get_legend(TASK_07,28) ) || ( who->get_legend(TASK_07,28) && !who->get_legend(TASK_07,29) ) )
		tmp += sprintf(ESC HIY "���Ѽ���\ntalk %x# welcome.4\n",getoid(this_object())); 
        if ( ( who->get_level() >= 30 && !who->get_legend(TASK_09,1) ) || ( who->get_legend(TASK_09,1) && !who->get_legend(TASK_09,3) ) )
		tmp += sprintf(ESC HIY "���ɽ����Ŀ���\ntalk %x# welcome.6\n",getoid(this_object())); 

        tmp += ESC"�뿪\nCLOSE\n";
        send_user(who,"%c%s",':',get_name()+": \n    "+"/quest/word"->get_normal_word(this_object())+"\n    �͹٣���Ҫ����ʲô��\n"+ tmp);
}

// ������ס�޴���
void do_info()
{
        object me, who;
        string result, info;
        me = this_object();  who = this_player();
        TASK_MASTER_D->do_info(me, who);             
}

void do_exchange(string sArg)
{
	TASK_COLLECT_D->do_exchange(sArg,6015);
}

void do_inputx(string sArg)
{
	object me,who;
	me = this_object(); who = this_player();
	TASK_COLLECT_D->do_inputx(me,who,sArg,6015);
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
       	string *nTmp,tmp;     
           
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_level() >= 30 && !who->get_legend(TASK_07,25)  )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����Ļ�Ե�ѵ�����֪���Ƿ�Ը���������Ե�ˣ����Ѵ޴���˵ļ����أ�\n    �޴����������ǰ��һ��ʧ����ʧȥ�˼��䣬�����������ź��Ӳ���ɥ��������������֮ǰ��������Ƭ��ë����ʧȥ�����ȴŪ��������Ƭ��ë�������������Ψһ��ʹ���ָ�����ķ����ˣ���ȥ�ռ�����Ƭ��ë������ɣ����ٸ�������һ����ô����\n    ��ë��۶�������������ϳ��ֹ���\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_07,25) && !who->get_legend(TASK_07,26) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������ҵ�����Ƭ��ë���޴���˵ļ��俴���ǻָ���������\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_07,26) && !who->get_legend(TASK_07,27) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ҵ�������Ƭ��ë������ϣ���ָ��޴���˵ļ����ˣ�\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
        case 2:
        	if ( who->get_level() >= 30 && !who->get_legend(TASK_07,25)  )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_07,25);
        		who->delete_save_2("spyumao");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_CHUGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,11,"��Ƭ��ë" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��Ƭ��ë");
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_07,26) && !who->get_legend(TASK_07,27) )
        	{
        	
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_07,27);
        		who->delete_save_2("spyumao");
			who->add_exp(1800);
			who->add_potential(30);
			who->add_cash(1500);
			send_user(who,"%c%s",';',"��Ƭ��ë ���� 1800 Ǳ�� 30 ��Ǯ 1500");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,11,"" );
			me->do_welcome(4);
        	}
        	break;
        case 4:
        	if ( who->get_legend(TASK_07,27) && !who->get_legend(TASK_07,28) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���Ѿ�����������Ƭ��ë��������Ƭ��ë��Ψһ���ܻ�ʹ�޴���˻ָ��������Ʒ����Ϊ��������������ʱ���µġ�\n    �޴����ʧȥ������һֱ��ס��κ���Ĵ������ڣ��㽫����Ƭ��ë�������������ܲ���ʹ���ָ����䡣\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_07,28) && !who->get_legend(TASK_07,29) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �㲻ȥ��ô֪������Ƭ��ë�ܲ��ܻ��Ѵ޴���˵ļ����أ�\n"ESC"�뿪", me->get_name()));
        	break;
        case 5:
        	if ( who->get_legend(TASK_07,27) && !who->get_legend(TASK_07,28) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_07,28);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_CHUGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,12,"���Ѽ���" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���Ѽ���");
        	}
        	break;
        case 6:
        	if ( who->get_level() >= 30 && !who->get_legend(TASK_09,1) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������۶�����Ĵ��ɽ�Ŵ���һ����Ŀ޺�������ΡΡ�ģ����ߣ�ȴ�����踺�أ���ɽ����Ʈ�����þò���ɢȥ��\n    �Ҳ���������������һ�ֿ޺���Ҳ��֪��ȷ�еķ�λ������������ᵽ����ʹ����˺���ѷΡ��γ���ϣ�������ȴ���ҿ�������ѹ��ȴ���ҷ�����ֻ������һ�����Ŀ޺���ϴ�ѡ���й���Ļ��ܵ�����������\n    �Ҳ��룬Ӧ�������Ŵ����������۸�������۶�������ɽ�ŵ��ϰ��գ����ȥ�����ɡ�\n"ESC"��������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_09,1) && !who->get_legend(TASK_09,2) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ڲ��úý�ѵ�Ƕ�ԣ��Ժ�ǳ����Ҳ��ɡ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_09,2) && !who->get_legend(TASK_09,3) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��ѵ�ĺã���ѵ�ĺð����Ǹó���һ��������Ȼ�Ժ�֪�ж�����Ҫ���ꡣ\n"ESC"�������\ntalk %x# welcome.8\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 7:
        	if ( who->get_level() >= 30 && !who->get_legend(TASK_09,1) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_09,1);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_CHUGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,23,"���ɽ����Ŀ���" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���ɽ����Ŀ���");
        	}
        	break;
        case 8:
        	if ( who->get_legend(TASK_09,2) && !who->get_legend(TASK_09,3) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;
        		nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),0,30,WAIST_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			TASK_LEGEND_D->give_item(who,tmp,1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_09,3);
			who->add_exp(2700);
			who->add_potential(100);
			who->add_cash(2000);
			send_user(who,"%c%s",';',sprintf("���ɽ����Ŀ��� ���� 2700 Ǳ�� 100 ��Ǯ 2000 %s 1",tmp->get_name()));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,23,"" );
        	}
        	break;   
        }

}
