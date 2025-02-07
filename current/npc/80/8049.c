
// �Զ����ɣ�/make/npc/make-biao

#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <equip.h>

inherit OFFICER;

void do_task_start();
void do_task_cancel();

// ��������ȡ��������
int get_char_picid() { return 5601; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("�̷�");
        set_city_name("���");

	set_2( "talk", ([
                "welcome"        : (: do_welcome :),
        ])); 
//	set("level",47);
//	set("legend",({32*12+13}));
	set("mpLegend",([45:({32*12+13}),50:({32*15+18})]));
	set("mpLegend2",([0:({32*10+7,32*31+17,32*31+20,32*31+23,32*31+26,}),45:({32*12+15,}),50:({32*15+20})]));
        setup();
}

void do_look( object who )
{
	object me = this_object();
	string tmp="";
	
	if ( who->get("escort.finish") == 1 )
	{
		TASK_ESCORT_D->do_look_2( who, me ); 
		return ;
	}
        if(     who->get_quest("escort.flag")    // ��������
        &&      who->get_quest("escort.leader") == 1    // �ӳ����
        &&      who->get_quest("escort.name") == get_name() 
        && 	who->get_quest("escort.city")+"��" == get_city_name() )    // �Ҷ�����
        {
		TASK_ESCORT_D->do_look_2( who, me ); 
		return ;
	}        
	
        tmp += CHAIN_D->get_chain_menu(who,me);
	if ( who->get_legend(TASK_10,6) && !who->get_legend(TASK_10,7) )
		tmp += sprintf(ESC HIY "�����Ŀ���\ntalk %x# welcome.1\n",getoid(me));
	if ( ( who->get_level() >= 45 && !who->get_legend(TASK_12,13) ) || ( who->get_legend(TASK_12,13) && !who->get_legend(TASK_12,15) ) )
		tmp += sprintf(ESC HIY "�̷�ķ���\ntalk %x# welcome.1\n",getoid(me));
	if ( ( who->get_level() >= 50 && !who->get_legend(TASK_15,18) ) || ( who->get_legend(TASK_15,18) && !who->get_legend(TASK_15,20) ) )
		tmp += sprintf(ESC HIY "�������Ŀ���\ntalk %x# welcome.5\n",getoid(me));
	if ( who->get_legend(TASK_31,16) && !who->get_legend(TASK_31,17) )
		tmp += sprintf(ESC HIY "����֪��������\ntalk %x# welcome.8\n",getoid(me));
	if ( (who->get_legend(TASK_31,17) && !who->get_legend(TASK_31,18)) || (who->get_legend(TASK_31,18) && !who->get_legend(TASK_31,20)) )
		tmp += sprintf(ESC HIY "��ħ���\ntalk %x# welcome.8\n",getoid(me));
	if ( (who->get_legend(TASK_31,20) && !who->get_legend(TASK_31,21)) || (who->get_legend(TASK_31,21) && !who->get_legend(TASK_31,23)) )
		tmp += sprintf(ESC HIY "��������\ntalk %x# welcome.8\n",getoid(me));
	if ( (who->get_legend(TASK_31,23) && !who->get_legend(TASK_31,24)) || (who->get_legend(TASK_31,24) && !who->get_legend(TASK_31,26)) )
		tmp += sprintf(ESC HIY "�������\ntalk %x# welcome.8\n",getoid(me));
			
	send_user(who,"%c%s",':',sprintf( "%s��\n    �ܹ��ľ����ھ�ξ������ͷ���ո�ǿ�����Ժ�ˬ������һ���ú���\n", get_name(),  ) 
			+ tmp +
			ESC"�뿪"
			);

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
        string cmd1,*nTmp,tmp;
           
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_legend(TASK_10,6) && !who->get_legend(TASK_10,7) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ԭ������ס����ʯ���⼸��ɰ����Ҳ��ˣ�����;�������͹�ȥ����λ%s����л�����Ǻ�����ڡ�\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),NPC_RANK_D->get_respect_2(who),getoid(me)));
        	else if ( who->get_level() >= 45 && !who->get_legend(TASK_12,13) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ǰ�죬�Ҿ���֣������ʱ��С�İѼҴ�������������ʧ��������ܰ��ҽ���Ѱ����\n"ESC"��������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_12,13) && !who->get_legend(TASK_12,14) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������ô������˽�������\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_12,14) && !who->get_legend(TASK_12,15) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��л%s��������һ����æ��\n"ESC"�������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),NPC_RANK_D->get_respect_2(who),getoid(me)));
        		
        	break;
        case 2:
        	if( who->get_legend(TASK_10,6) && !who->get_legend(TASK_10,7) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;  
        		TASK_LEGEND_D->give_item(who,"item/product/61004",1);
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_10,7);
			who->add_exp(3500);
			who->add_potential(90);
			who->add_cash(2500);
			send_user(who,"%c%s",';',"�������̷磨2�� ���� 3500 Ǳ�� 90 ��Ǯ 2500 С����ͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,10,"" );
        	}
        	break;
	case 3:
        	if( who->get_level() >=45 && !who->get_legend(TASK_12,13) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_12,13);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,5,"�̷�ķ���" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�̷�ķ���");
        	}
        	break;       
        case 4:
        	if ( who->get_legend(TASK_12,14) && !who->get_legend(TASK_12,15) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"������",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_12,15);
			who->add_exp(4800);
			who->add_potential(170);
			who->add_cash(4200);
			send_user(who,"%c%s",';',"�̷�ķ��� ���� 4800 Ǳ�� 170 ��Ǯ 4200");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,5,"" );
        	}
        	break;   
	case 5:
        	if ( who->get_level() >=50 && !who->get_legend(TASK_15,18) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����������˼�λ���������Ŀ��ˣ�ÿ�����ﶼҪ�����������������������Ե��٣���������������������ȥ�೤�Ǹ������ң����ܲ����ҵ�20��������\n"ESC"��������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_15,18) && !who->get_legend(TASK_15,19) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���һ�ٷ��������Ƿ������������������Ͼ����ˣ�һ�����ڼҺ����ģ�ʵ���ǲ���������ô���߰���\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_15,19) && !who->get_legend(TASK_15,20) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���Ǻܾ�û�����Ҽ��ˣ�ƾ��������Ҿ��ܰ������������ˣ��ٺ١�\n"ESC"�������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
	case 6:
        	if( who->get_level() >=50 && !who->get_legend(TASK_15,18) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_15,18);
        		who->delete_save_2("cflajiao");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,34,"�������Ŀ���" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�������Ŀ���");
        	}
        	break;       
        case 7:
        	if ( who->get_legend(TASK_15,19) && !who->get_legend(TASK_15,20) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"����",20) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_15,20);
        		who->delete_save_2("cflajiao");
			who->add_exp(6300);
			who->add_potential(252);
			who->add_cash(5300);
			send_user(who,"%c%s",';',"�������Ŀ��� ���� 6300 Ǳ�� 252 ��Ǯ 5300");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,34,"" );
        	}
        	break;  
	case 8:
        	if ( who->get_legend(TASK_31,16) && !who->get_legend(TASK_31,17) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��֪������������ҵģ�û�취�����ǵ������ǹ�ͬ���ص����ܣ����ڳ������⣬���ǵ��������е���\n"ESC"�������\ntalk %x# welcome.9\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_31,17) && !who->get_legend(TASK_31,18) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������������Ѿ������˺ܾã�����ֽ���ڰ���ס���ˡ�\n    ����ǰ������ȥ����ɽ���ԣ������п���һ����̳���и�����������������ã�״�����ĵ��������������дʣ�������ˮ����ʡ���ī�����ޡ�����ʲôһͨ���߰��㣬�Ϳɼ�ص��ѿ�һ������׵Ĵ󶴣�һ�ź�����г������������۽�Ũ��������һЩ���ι�״��Ӱ�ӽ������ͣ��ɹ�Ũ�ҵ������������������û�е���ȥ�ƻ���̳���ʹ����ˣ��������ʱʱ�����ں�����������������ֳ�û���˵���Ϣ��������ΪΨһ֪���ˣ���Ȼ�������Ӳ�������֪�����ǵ��ϳ��������Լ�����������ֻ����׳ʿʩ��Ԯ�֣�����ǰ����ħ�����������������а���߸����������ǵ�а�����������ٸ�������ô����\n"ESC"��������\ntalk %x# welcome.10\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_31,18) && !who->get_legend(TASK_31,19) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����������µ���ֻ�����������ܣ������ʵ���ǲ���ɱ�����ǣ���ô��ͷ����ɡ�\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_31,19) && !who->get_legend(TASK_31,20) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ţ���Ща������ֻ���Ƴ���Ⱥ���ֵķ�����������û�ܽ���������⣬\n"ESC"�������\ntalk %x# welcome.11\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_31,20) && !who->get_legend(TASK_31,21) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������������Ѿ������˺ܾã�����ֽ���ڰ���ס���ˡ�\n    ����ǰ������ȥ����ɽ���������˿�̳������͵�����������е���ħ��ֶ����˳����ˣ��������������ֻ����������ſ����Ʒ����ǣ������������������ħ��Ϊ�˲������õ���Ը����ǣ���Щ������������������������������Ϊ�˲��ǻ������ͱ�����������ܡ�\n    ����������������ֳ�û���˵���Ϣ��������ΪΨһ֪���ˣ���Ȼ�������Ӳ�����������ȥ��ħ��1����������������Ȼ�����������ɡ�\n"ESC"��������\ntalk %x# welcome.12\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_31,21) && !who->get_legend(TASK_31,22) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ѵ���Ȼ�޷�����������ô������˼���ң�Ϊ�����ǵ�����ų�����ҵ�ֻ��һ��л�����ˡ�\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_31,22) && !who->get_legend(TASK_31,23) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������������⣬����ֻ���õ���������ˡ�\n"ESC"�������\ntalk %x# welcome.13\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_31,23) && !who->get_legend(TASK_31,24) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ھ������·�ӡ��Щ���ֵĹؼ��ˣ���ħ���е��������������Щ�������������֮Դ��Ҳ�ǿ������ǵ�������������������е�ʱ������������ǵ������������������ϵķ�ӡ���������⣬�ͳ�Ϊ���������������������ط�ӡ�ķ�����������ȥħ�����������������ղſ��������Ĺ����Ѿ�����ɱ���ˡ�\n"ESC"��������\ntalk %x# welcome.14\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_31,24) && !who->get_legend(TASK_31,25) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���û������������һ��治֪����¸���ô���������������\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_31,25) && !who->get_legend(TASK_31,26) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �õ������������������ٺͳ��ֿ�����һ�£��������лл���ˣ�\n"ESC"�������\ntalk %x# welcome.15\n"ESC"�뿪", me->get_name(),getoid(me)));

        	break;
        case 9:
        	if ( who->get_legend(TASK_31,16) && !who->get_legend(TASK_31,17) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_31,17);
			who->add_exp(30000);
			who->add_potential(600);
			who->add_cash(29000);
			send_user(who,"%c%s",';',"���ܣ�1�� ���� 30000 Ǳ�� 600 ��Ǯ 29000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,36,"" );
        		me->do_welcome(8);
        	}
        	break;
        case 10:
        	if ( who->get_legend(TASK_31,17) && !who->get_legend(TASK_31,18) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_31,18);
        		who->delete_save("cfkuly");
        		who->delete_save("cfxieling");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,39,"���ܣ�2��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���ܣ�2��");
        	}
        	break;  
        case 11:
        	if ( who->get_legend(TASK_31,19) && !who->get_legend(TASK_31,20) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_31,20);
        		who->delete_save("cfkuly");
        		who->delete_save("cfxieling");
			who->add_exp(35000);
			who->add_potential(620);
			who->add_cash(32000);
			send_user(who,"%c%s",';',"���ܣ�2�� ���� 35000 Ǳ�� 620 ��Ǯ 32000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,39,"" );
        		me->do_welcome(8);
        	}
        	break;  
        case 12:
        	if ( who->get_legend(TASK_31,20) && !who->get_legend(TASK_31,21) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_31,21);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,40,"���ܣ�3��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���ܣ�3��");
        	}
        	break;  
        case 13:
        	if ( who->get_legend(TASK_31,22) && !who->get_legend(TASK_31,23) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;
			TASK_LEGEND_D->give_item(who,"item/product/64160",1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_31,23);
			who->add_exp(40000);
			who->add_potential(650);
			who->add_cash(37000);
			send_user(who,"%c%s",';',"���ܣ�3�� ���� 40000 Ǳ�� 650 ��Ǯ 37000 ����ѥͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,40,"" );
        		me->do_welcome(8);
        	}
        	break;  
        case 14:
        	if ( who->get_legend(TASK_31,23) && !who->get_legend(TASK_31,24) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_31,24);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YANGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,41,"���ܣ�4��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���ܣ�4��");
        	}
        	break;  
        case 15:
        	if ( who->get_legend(TASK_31,24) && !who->get_legend(TASK_31,26) )
        	{
        		nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),who->get_gender(),90,WAIST_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
        		if (TASK_LEGEND_D->check_task_item(who,"�������",1) != 1 )
        			return;
			TASK_LEGEND_D->give_item(who,tmp,1);
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_31,26);
			who->add_exp(150000);
			who->add_potential(1800);
			who->add_cash(140000);
			send_user(who,"%c%s",';',sprintf("���ܣ�4�� ���� 150000 Ǳ�� 1800 ��Ǯ 140000 %s 1",tmp->get_name()));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YANGUO,41,"" );
        	}
        	break; 
        }
}