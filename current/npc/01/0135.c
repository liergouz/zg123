
#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <music.h>

inherit OFFICER;
void do_welcome(string arg);

// ��������ȡ��������
int get_char_picid() { return 5901; }

// ���������촦��
void create()
{
        set_name( "����ͷ" );
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));
//        set("level", 0);
//        set("legend", ({ 32*2+26 }));
	set("mpLegend2",([5:({32*40+21,}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
        string tmp="";

/*        if( who->get_level() >= 5 && !who->get_legend(TASK_NEWBIE_02, 27) )
        {
		tmp = sprintf(ESC"�����˵�С�۷�\ntalk %x# welcome.1\n",getoid(this_object()));
        }*/
        if( who->get_legend(TASK_40, 20) && !who->get_legend(TASK_40, 21) )
        {
		tmp += sprintf(ESC +HIY+ "�¶�\ntalk %x# welcome.4\n",getoid(this_object()));
        }
        tmp += CHAIN_D->get_chain_menu(who,this_object());
        send_user( who, "%c%s", ':', get_name() + "��\n�Դӽ�ѵ�˵����˺�����û�������ˣ���������кܶ�С�۷������ˣ�Ҳͦ����ģ�\n"
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
	int flag,i,j,k,size,p;
	object who,item,*inv;
	
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
	case 1:
		if( who->get_level() >= 5 && !who->get_legend(TASK_NEWBIE_02, 26) )
			send_user(who,"%c%s",':',sprintf("%s:\n    ��������Χ��ЩС�۷䣬��ǰͦ���Ƶģ��������֪����ô��ģ�������ħһ����������Ⱥ��ӵĹ�����Χ�����ˡ����գ����¿��������Σ����ǵ���֮���ǵþ������������ǡ����������ã������ɣ�\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪",me->get_name(),getoid(me)));
		else if ( who->get_save_2("xiaomifeng") < 8 )
			send_user(who,"%c%s",':',sprintf("%s:\n    ��֣���ô�����㻹û����������ǣ��ѵ����ǵĶ����빥�����������ˣ�����������Ѷȣ���þ���ѽ��\n"ESC"�뿪",me->get_name()));
		else 
			send_user(who,"%c%s",':',sprintf("%s:\n    ��ʵ��ɱ���⼸ֻС�۷�Ҳֻ�Ǳ�ˮ��н������Ҫ�Ļ���ץ���Ǹ�Ļ����֣����ǵ�ƾ��һ�˵������ǲ�̫���ܵġ����»��ôӳ����顣����������Щ�����ɣ�\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪",me->get_name(),getoid(me)));
			break;
	case 2:
		if( who->get_level() >= 5 && !who->get_legend(TASK_NEWBIE_02, 26) )
		{
			who->set_legend(TASK_NEWBIE_02, 26);
			who->delete_save_2("xiaomifeng");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_YEWAI,"��Ϫ" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YEWAI,2,"�����˵�С�۷�" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�����˵�С�۷�");	
		}
		break;	
	case 3:
		if ( who->get_legend(TASK_NEWBIE_02, 26) && !who->get_legend(TASK_NEWBIE_02, 27) && who->get_save_2("xiaomifeng") >= 8 )
		{
			item = new("item/91/9140");
			item->set_amount(5);
			p = item->move(who,-1);
			if ( !p )
			{
				send_user(who,"%c%s",'!',"�����ϵĶ���̫��");
				destruct(item);
				return;
			}
			who->delete_save_2("xiaomifeng");
			item->add_to_user(p);
			who->add_exp(370);
			who->add_potential(30);
			who->add_cash(2000);
			who->set_legend(TASK_NEWBIE_02, 27);
			send_user(who,"%c%s",';',"�����˵�С�۷� ���� 370 Ǳ�� 30 ��Ǯ 2000 �ٶ�ɢ 5");			
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YEWAI,2,"" );
		}
		break;		
	case 4:
		if( who->get_legend(TASK_40, 20) && !who->get_legend(TASK_40, 21) )
			send_user(who,"%c%s",':',sprintf("%s:\n    �����������������Ѿ���30��û�м������ˣ��ҵøϿ�ȥ�������λ���ѡ�\n"ESC"�������\ntalk %x# welcome.5\n"ESC"�뿪",me->get_name(),getoid(me)));
		break;
	case 5:
		if( who->get_legend(TASK_40, 20) && !who->get_legend(TASK_40, 21) )
		{
			if (TASK_LEGEND_D->check_task_item(who,"�����",1) != 1 )
        			return;
        		TASK_LEGEND_D->task_finish(who);
			who->add_exp(200);
			who->add_potential(30);
			who->add_cash(1000);
			who->set_legend(TASK_40, 21);
			send_user(who,"%c%s",';',"�¶� ���� 200 Ǳ�� 30 ��Ǯ 1000");			
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,34,"" );
		}
		break;	
	}
}