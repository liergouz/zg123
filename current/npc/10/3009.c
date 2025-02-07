
// �Զ����ɣ�/make/npc/make-collect

#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <task.h>
#include <music.h>

inherit OFFICER;

void do_task();

// ��������ȡ��������
int get_char_picid() { return 5801; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("���Ϻ�");
	set_2( "talk", ([
                "welcome"        : (: do_welcome :),
        ]));
	set("mpLegend2",([0:({32*46+2,32*46+5,32*47+16,}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
	string tmp="";
	object me=this_object();
        tmp += CHAIN_D->get_chain_menu(who,this_object());
        if ( who->get_legend(TASK_46,1)&&!who->get_legend(TASK_46,2) ) 
		tmp += sprintf(ESC HIY "ȷ�ϴ�˵\ntalk %x# welcome.1\n",getoid(me)); 
        if ( who->get_legend(TASK_46,2)&&!who->get_legend(TASK_46,5) ) 
		tmp += sprintf(ESC HIY "��������\ntalk %x# welcome.1\n",getoid(me)); 
        if ( who->get_legend(TASK_46,5)&&!who->get_legend(TASK_46,6) ) 
		tmp += sprintf(ESC HIY "ѯ����Ϣ\ntalk %x# welcome.1\n",getoid(me)); 
        if ( who->get_legend(TASK_47,15)&&!who->get_legend(TASK_47,16) ) 
		tmp += sprintf(ESC HIY "�������\ntalk %x# welcome.6\n",getoid(me)); 
        if ( who->get_legend(TASK_47,16)&&!who->get_legend(TASK_47,17) ) 
		tmp += sprintf(ESC HIY "�Ƴ�ҥ��\ntalk %x# welcome.6\n",getoid(me)); 

        send_user( who, "%c%s", ':', sprintf( "%s��\n    ����ֵ�ý�����������ǣ��Ⱳ��û������ˣ�\n", get_name())
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
        string cmd1;
       	string *nTmp,tmp;     
           
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
		if ( who->get_legend(TASK_46,1)&&!who->get_legend(TASK_46,2) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����˵��������Ҳ����Ϊ���Σ����Ƿ׷״�˵�ж������併�٣���������ֵĴ����˶��������䣬����˶��ڼƻ����ߣ�ֻʣ�����Ǽ����Ϲ�ͷ��һЩ�޴���ȥ�Ĺ¶���ĸ��ɷ�������������޷����ڵ��ǲ�֪��ʱ���ٵĶ��˰��ˡ�\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_46,2)&&!who->get_legend(TASK_46,3) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ո����˸����ҵ���֮���������С����ɱ¾������Ϊ��������굾������������������˵�������ʯ�����������������һ���ϲ��������������ķ��ƴ��Σ���Ȼ��֪����������ΪΪ��������˶�ô��Ļ�������ȥ����ɱ��������������ͷ������Ʒ���������ƽϢ�����ŭ����\n"ESC"��������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_46,3)&&!who->get_legend(TASK_46,4) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������������ѹ�ͷҲҪ�����ˡ�\n"ESC"�뿪", me->get_name()));
		else if ( who->get_legend(TASK_46,4)&&!who->get_legend(TASK_46,5) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��л��ʿ��������ƽ�����ҵøϿ����˸�����������굾ű���ʿ���ˣ������ͷ�������Ǿ�ȥ�ڷ��ڵ���ļ����ϣ���Ը�ܹ�����ֻ��ɡ�\n"ESC"�������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_46,5)&&!who->get_legend(TASK_46,6) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���������������������������굾ţ����֪��������Ϊ����ǰ;��ռһ�ԣ����Ѿ����˱�������ˣ�������ȥ����ռһ�԰ɡ�\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));

 	      	break;
     
        case 2:
        	if( who->get_legend(TASK_46,1)&&!who->get_legend(TASK_46,2) )
        	{
        		who->set_legend(TASK_46,2);
			who->add_exp(82000);
			who->add_potential(980);
			who->add_cash(68000);
			send_user(who,"%c%s",';',"���괫˵1 ���� 82000 Ǳ�� 980 ��Ǯ 68000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,64,"" );
			me->do_welcome(1);
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_46,2)&&!who->get_legend(TASK_46,3) )
        	{
        		who->set_legend(TASK_46,3);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,65,"���괫˵2" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���괫˵2");
       		}
        	break;
        case 4:
        	if( who->get_legend(TASK_46,4)&&!who->get_legend(TASK_46,5) )
        	{
        		who->set_legend(TASK_46,5);
			who->add_exp(83000);
			who->add_potential(920);
			who->add_cash(96000);
			send_user(who,"%c%s",';',"���괫˵2 ���� 83000 Ǳ�� 920 ��Ǯ 96000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,65,"" );
			me->do_welcome(1);
        	}
        	break;
        case 5:
        	if ( who->get_legend(TASK_46,5)&&!who->get_legend(TASK_46,6) )
        	{
        		who->set_legend(TASK_46,6);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,66,"���괫˵3" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"���괫˵3");
       		}
        	break;
        case 6:
		if ( who->get_legend(TASK_47,15)&&!who->get_legend(TASK_47,16) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("�������������Ϻ���ɫ���ˣ����е�ˮ�����䵽����ˤ�˸�����\n"ESC"�������\ntalk %x# welcome.7\n"ESC"�뿪", getoid(me)));
		else if ( who->get_legend(TASK_47,16)&&!who->get_legend(TASK_47,17) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("�����Ϻ��ò���������ʰ�˵����ϵ���Ƭ������������ɨ£���������·��㲻����һ����������Щ��������Ϻ�����̧��ͷ����������������⣩��Щ���������ϴμ�������֮���������Ϲ������ġ���֪�����ˣ����������ȷ����û��������Դ�������д�˷������飬������ҽ���������ʷ���ˡ�\n"ESC"��������\ntalk %x# welcome.8\n"ESC"�뿪", getoid(me)));

		break;
        case 7:
        	if( who->get_legend(TASK_47,15)&&!who->get_legend(TASK_47,16) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;
			TASK_LEGEND_D->give_item(who,"item/product/64189",1); 	
        		who->set_legend(TASK_47,16);
			who->add_exp(95000);
			who->add_potential(1200);
			who->add_cash(97000);
			send_user(who,"%c%s",';',"�Ƴ�ҥ��4 ���� 95000 Ǳ�� 1200 ��Ǯ 97000 �����װͼֽ 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,82,"" );
			me->do_welcome(6);
        	}
        	break;
        case 8:
        	if ( who->get_legend(TASK_47,16)&&!who->get_legend(TASK_47,17) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;
        		TASK_LEGEND_D->give_item(who,"item/98/0234",1); 
        		who->set_legend(TASK_47,17);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QINGUO,"�ع�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QINGUO,83,"�Ƴ�ҥ��5" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�Ƴ�ҥ��5");
       		}
        	break;
        }
}