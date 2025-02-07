
#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <music.h>

inherit OFFICER;

void do_welcome(string arg);

// ��������ȡ��������
int get_char_picid() { return 5909; }

// ���������촦��
void create()
{
        set_name( "��Сë" );

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));
//        set("level", 0);
//        set("legend", ({ 32*2+24 }));
	set("mpLegend2",([5:({32*2+25,}),]));
        setup();
}

// �������Ի�����
void do_look( object who )
{
        string tmp="";
   
        if( who->get_legend(TASK_NEWBIE_02, 24) && !who->get_legend(TASK_NEWBIE_02, 25) )
        {
		tmp = sprintf(ESC +HIY+ "��ζ������\ntalk %x# welcome.1\n",getoid(this_object()));
        }   
        send_user( who, "%c%s", ':', get_name() + "��\n����������ϲ������Ķ���������˵�춹�������̶����������б��Ǻ�«��\n" 
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
	int flag,i,j,k,size,p,amount;
	object who,item,*inv;
	
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
	case 1:
		if ( who->get_legend(TASK_NEWBIE_02, 24) && who->get_save_2("xiaomao_fengmi") < 3 )
			send_user(who,"%c%s",':',sprintf("%s:\n    %s���ǲ�����̫�����ˣ��㲻ϲ���ң����Բ������������أ�\n"ESC"�뿪",me->get_name(),who->get_gender()==1?"���":"���"));
		else if ( who->get_legend(TASK_NEWBIE_02, 24) && who->get_save_2("xiaomao_fengmi") >= 3 )
			send_user(who,"%c%s",':',sprintf("%s:\n    ������%s���Ǹ�����ˡ���Щ�����������̸��ҵģ���һֱû����ã������ţ��͵��Һ��㽻������Ŷ��\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪",me->get_name(),who->get_gender()==1?"���":"���",getoid(me)));
				
		break;

	case 3:
		if ( who->get_legend(TASK_NEWBIE_02, 24) && who->get_save_2("xiaomao_fengmi") >= 3 )
		{
			if (TASK_LEGEND_D->check_task_item(who,"����",3) != 1 )
        			return;
			item = new("item/32/3282");
			item->set_amount(8);
			p = item->move(who,-1);
			if ( !p )
			{
				send_user(who,"%c%s",'!',"�����ϵĶ���̫��");
				destruct(item);
				return;
			}
			TASK_LEGEND_D->task_finish(who);
			who->delete_save_2("xiaomao_fengmi");
			item->add_to_user(p);
			who->add_exp(380);
			who->add_potential(20);
			who->set_legend(TASK_NEWBIE_02, 25);
			send_user(who,"%c%s",';',"��ζ������ ���� 380 Ǳ�� 20 ���� 8");			
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_YEWAI,1,"" );
		}
		break;
	}
}