
// �Զ����ɣ�/make/npc/make8084

#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 5505; }
void do_welcome( string arg );

int is_self_look() { return 1; }

// ������С��ʶ��
int is_seller() { return 1; }

// ���������촦��
void create()
{
        set_name("��������");
	set_real_name("��Ӯ(�÷�69~79)");
        set_city_name("����");
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ])); 
//	set("level",18);
//	set("legend",({32*4+17}));
 	set("mpLegend",([15:({32*4+17,32*4+23}),70:({32*22+27,}),75:({32*25+4,}),80:({32*26+22,}),60:({32*51+7})]));
	set("mpLegend2",([0:({32*26+4,}),15:({32*4+18,32*4+25}),70:({32*22+29,}),60:({32*51+9})]));
        set_2( "good", ([
                "01" : "/item/product/64116",
                "02" : "/item/product/64117",
                "03" : "/item/product/64118",
                "04" : "/item/product/64119",
                "05" : "/item/product/64120",
                "06" : "/item/product/64121",
                "07" : "/item/product/64122",
                "08" : "/item/product/64123",
                "09" : "/item/product/64124",
                "10" : "/item/product/64125",
                "11" : "/item/product/64126",        
                "12" : "/item/product/64127",
                "13" : "/item/product/64128",
                "14" : "/item/product/64129",
                "15" : "/item/product/64130",      
                "16" : "/item/product/64131",
                "17" : "/item/product/64132",
                "18" : "/item/product/64133",
                "19" : "/item/product/64134",
                "20" : "/item/product/64135",
                "21" : "/item/product/64136",        
                "22" : "/item/product/64137",
                "23" : "/item/product/64138",                                       
                "24" : "/item/product/64139",
        ]) ); 	
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
	object me = this_object();
	
	if ( ( who->get_level() >= 15 && !who->get_legend(TASK_04,17) ) || ( who->get_legend(TASK_04,17) && !who->get_legend(TASK_04,18) ) )
	{
		tmp = sprintf(ESC HIY "���յ�����\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( ( who->get_level() >= 15 && !who->get_legend(TASK_04,23) ) || ( who->get_legend(TASK_04,23) && !who->get_legend(TASK_04,25) ) )
	{
		tmp += sprintf(ESC HIY "�Ͷ�����\ntalk %x# welcome.5\n",getoid(me));
	}
	if ( ( who->get_level() >= 70 && !who->get_legend(TASK_22,27) ) || ( who->get_legend(TASK_22,27) && !who->get_legend(TASK_22,29) ) )
	{
		tmp += sprintf(ESC HIY "���˵�ˮ��\ntalk %x# welcome.8\n",getoid(me));
	}
	if ( who->get_level() >= 75 && !who->get_legend(TASK_25,4) )
	{
		tmp += sprintf(ESC HIY "��ȡ��ͼ\ntalk %x# welcome.11\n",getoid(me));
	}
	if ( who->get_legend(TASK_26,3) && !who->get_legend(TASK_26,4) )
		tmp += sprintf(ESC HIY "��ʷ�Ľ���\ntalk %x# welcome.13\n",getoid(me));
	if ( who->get_legend(TASK_26,4) && !who->get_legend(TASK_26,5) )
		tmp += sprintf(ESC HIY "ָ������\ntalk %x# welcome.13\n",getoid(me));
	if ( who->get_level() >= 80 && !who->get_legend(TASK_26,22) )
		tmp += sprintf(ESC HIY "���յĺ���\ntalk %x# welcome.16\n",getoid(me));
	if ( (who->get_level() >= 60 && !who->get_legend(TASK_2_01,7)) || (who->get_legend(TASK_2_01,7) && !who->get_legend(TASK_2_01,9)))
		tmp += sprintf(ESC HIY "ǧ��Ѱ��\ntalk %x# welcome.18\n",getoid(me));

	tmp += sprintf(ESC"�������\nlist %x#\n", getoid(me));
	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) + "\n",get_name(),getoid(me)) +
		tmp +
		ESC"�뿪");
	else
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) ,get_name()));
	
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
        	if ( who->get_level() >= 15 && !who->get_legend(TASK_04,17)  )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ϴ���ȥ�ڹ�̽�׵�·�ϲ�С�İ�����鴮Ū���ˣ����������޶��ӵİ׻�̳һ����ʧ�ġ��Ǵ����������ҵ������ӣ����˺ö�Ǯ����ģ���Ҫ���ܰ����һ�������һ�������ص�л�㡣\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_04,17) && !who->get_legend(TASK_04,18) )
			me->do_welcome(3);
        	break;
        case 2:
        	if ( who->get_level() >= 15 && !who->get_legend(TASK_04,17)  )
        	{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			TASK_LEGEND_D->remove_task_item(who, "����鴮");                   	
        		who->set_legend(TASK_04,17);
			who->delete_save("feicuizucuan");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_HANGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,8,"���յ�����" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���յ�����");
        	}
        	break;
        case 3:
        	if ( !who->get_legend(TASK_04,17) || who->get_legend(TASK_04,18) )
        		return ;
        	if ( objectp(item=present("����鴮",who,1,MAX_CARRY)) && item->is_legend_item() == 1 )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ̫лл���ˣ������Ǹ����ˣ��治֪����θ�л��źá�\n"ESC"�������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
		else
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ˣ��������ҵ�������鴮��ϣ����û���ˡ�\n"ESC"�뿪", me->get_name()));
        	break;
        case 4:
        	if ( who->get_legend(TASK_04,17) && !who->get_legend(TASK_04,18) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"����鴮",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_04,18);
			who->delete_save("feicuizucuan");
			who->delete_save_2("feicuizucuan");
			who->add_exp(1600);
			who->add_potential(80);
			who->add_cash(1200);
			send_user(who,"%c%s",';',"���յ����� ���� 1600 Ǳ�� 80 ��Ǯ 1200");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,8,"" );
        	}
        	break;
        case 5:
        	if ( who->get_level() >= 15 && !who->get_legend(TASK_04,23) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������ڳ����ˣ�������̫ƽ���������ꡣ�����һ���з�����������������������ҵ�Ǯ�ơ������ԣ�Ҫ���Ҳ������������������ҿ���һ����������������֮ʿ��%s��ɷ������ǰ��ճ�����һ�󺦣�\n"ESC"��������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),NPC_RANK_D->get_respect_2(who),getoid(me)));
		else if ( who->get_legend(TASK_04,24) && !who->get_legend(TASK_04,25) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    лл%s��ѽ�������ҿ��а��������ӹ��ˡ�\n"ESC"�������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),NPC_RANK_D->get_respect_2(who),getoid(me)));
        	else if ( who->get_legend(TASK_04,23) && !who->get_legend(TASK_04,24) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ˣ��һ��Ƕ��ڸ���һЩǮ������ð����ɣ�\n"ESC"�뿪", me->get_name()));
        	break; 
        case 6:
        	if ( who->get_level() >= 15 && !who->get_legend(TASK_04,23) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_04,23);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_HANGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,11,"�Ͷ�����" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�Ͷ�����");
        	}
        	break;
        case 7:
        	if ( who->get_legend(TASK_04,24) && !who->get_legend(TASK_04,25) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/final/33/1702",3);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_04,25);
			who->add_exp(1800);
			who->add_potential(80);
			who->add_cash(1600);
			send_user(who,"%c%s",';',"�Ͷ����� ���� 1800 Ǳ�� 80 ��Ǯ 1600 �ع��� 3");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,11,"" );
        	}
        	break;
        case 8:
        	if ( who->get_level() >= 70 && !who->get_legend(TASK_22,27) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������������һ��������ˮ��·�����˾���������ˮ������������ʵ�����ˮ��ֻ��һ��װ�ɹ��������ˮ������Ȼ�����ٲ���İ������ܣ�������Ѿ��в���·�����˱�����ɱ���ˣ���ȥ��취ɱ�������10�������İ��࣬Ϊ�����һ���ɣ�\n"ESC"��������\ntalk %x# welcome.9\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_22,27) && !who->get_legend(TASK_22,28) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������������Щ���࣬����Խ��Խ������ܺ�ѽ��\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_22,28) && !who->get_legend(TASK_22,29) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������������Ⱥ���˵İ����ˣ���Щ������·������֮��Ҳ�õ��˰�ο��\n"ESC"�������\ntalk %x# welcome.10\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
        case 9:
        	if ( who->get_level() >= 70 && !who->get_legend(TASK_22,27) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_22,27);
        		who->delete_save_2("hgbxsuigui");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_HANGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,43,"���˵�ˮ��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���˵�ˮ��");
        	}
        	break;  
        case 10:
        	if ( who->get_legend(TASK_22,28) && !who->get_legend(TASK_22,29) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_22,29);
        		who->delete_save_2("hgbxsuigui");
			who->add_exp(25000);
			who->add_potential(430);
			who->add_cash(23000);
			send_user(who,"%c%s",';',"���˵�ˮ�� ���� 25000 Ǳ�� 430 ��Ǯ 23000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,43,"" );
        	}
        	break;
        case 11:
        	if ( who->get_level() >= 75 && !who->get_legend(TASK_25,4)  )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������ȶ���һ�����ϵ����ܣ�����ȶ����һ�����صı��أ��Ǳ�������δ���˷��֡�����Ҫ�ҵ��Ǳ��ر�������һ����ȶ���ͼ����������˵�Ǳ�ͼ�ں������������ϣ���ȥ������Ҫ��\n"ESC"��������\ntalk %x# welcome.12\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break; 
        case 12:
       		if ( who->get_level() >= 75 && !who->get_legend(TASK_25,4)  )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_25,4);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_HANGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,16,"��ȡ��ͼ" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��ȡ��ͼ");
        	}        	
        	break;   	    
	case 13:
        	if ( who->get_legend(TASK_26,3) && !who->get_legend(TASK_26,4) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��˵���������Ҽ���������ʱ���Ҷ�˵����һ�������ɡ�������λ���������Ѿ���ʮ��ǰ�����ˡ�\n"ESC"�������\ntalk %x# welcome.14\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_26,4) && !who->get_legend(TASK_26,5) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ȱ𼱣���Ȼ�������Ѿ������ˣ�������������֮ǰ�չ�һ��ͽ�ܡ��Ǹ�ͽ�ܾ����ʿ�������ʿ��ס�����Ǻ�����������ȥ�������ɣ���Ȼ���ķ����������˲��Զ��������Ҳ��������ˮ������Ӧ�ÿ��԰������һ��æ��\n"ESC"��������\ntalk %x# welcome.15\n"ESC"�뿪", me->get_name(),getoid(me)));
  
		break;
	case 14:
        	if ( who->get_legend(TASK_26,3) && !who->get_legend(TASK_26,4) )
        	{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_26,4);
			who->add_exp(37000);
			who->add_potential(540);
			who->add_cash(37000);
			send_user(who,"%c%s",';',"��ʷ�Ľ��� ���� 37000 Ǳ�� 540 ��Ǯ 37000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,28,"" );
			me->do_welcome(13);
        	}
        	break;
	case 15:
        	if( who->get_legend(TASK_26,4) && !who->get_legend(TASK_26,5) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_26,5);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_HANGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,29,"ָ������" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"ָ������");
        	}
        	break; 
	case 16:
        	if ( who->get_level() >= 80 && !who->get_legend(TASK_26,22) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��˵ס��֣�Ǳ�������ʦ�������������׽�������ˣ���ʦ���ں���ܿ��յ����ӣ��Ҹ���ʦ���н��飬���������ȥο����ʦһ����\n"ESC"��������\ntalk %x# welcome.17\n"ESC"�뿪", me->get_name(),getoid(me)));
  
		break;
	case 17:
        	if( who->get_level() >= 80 && !who->get_legend(TASK_26,22) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_26,22);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_HANGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,36,"���յĺ���" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���յĺ���");
        	}
        	break; 
        case 18:
        	if ( who->get_level() >= 60 && !who->get_legend(TASK_2_01,7) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��λӢ�ۣ��Ҿ��е��ֳ����˴���˵�������ع���²��Ϊ���ۣ������������꣬ϣ�����ܹ������������������ǵط��׶༪�ٰ����������أ����ܲ��ܰ���ȥ�������ֳ����ڵ����䰡���������и�����Ϊ��������������ˣ�Ҳ������Ż����ɡ�\n"ESC"��������\ntalk %x# welcome.19\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_2_01,7) && !who->get_legend(TASK_2_01,8) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Ӣ�ۼ������ֳ�����\n"ESC"�뿪", me->get_name(),));
		else if ( who->get_legend(TASK_2_01,8) && !who->get_legend(TASK_2_01,9) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����أ��ҿ������ֳ�����������ô��ĸ��˵��������λӢ�ۣ�����лл���ˡ�\n"ESC"�������\ntalk %x# welcome.20\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
        case 19:
        	if ( who->get_level() >= 60 && !who->get_legend(TASK_2_01,7) )
        	{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_2_01,7);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_HANGUO,"����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,101,"ǧ��Ѱ��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"ǧ��Ѱ��");
		}
        	break;
        case 20:
        	if ( who->get_legend(TASK_2_01,8) && !who->get_legend(TASK_2_01,9) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"�ֳ�������",1) != 1 )
        			return;
        		TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_2_01,9);
			who->add_exp(16800);
			who->add_potential(500);
			who->add_cash(9600);
			send_user(who,"%c%s",';',"ǧ��Ѱ�� ���� 16800 Ǳ�� 500 ��Ǯ 9600");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_HANGUO,101,"" );
        	}
        	break;
        }
}