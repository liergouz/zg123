// �Զ����ɣ�/make/npc/make-biao

#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <public.h>

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 9715; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("����ʿ");
        set_city_name("�ܹ�");

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));      
	set("mpLegend2",([0:({32*40+6,32*40+9,32*40+12,}),]));
        setup();
}
// �������Ի�����
void do_look( object who )
{
	string tmp="";
        if ( who->get_legend(TASK_40,5) && !who->get_legend(TASK_40,6) ) 
		tmp += sprintf(ESC HIY "����ĺŽ�\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( who->get_legend(TASK_40,6) && !who->get_legend(TASK_40,9) ) 
		tmp += sprintf(ESC HIY "��ʧ�����\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( who->get_legend(TASK_40,9) && !who->get_legend(TASK_40,12) ) 
		tmp += sprintf(ESC HIY "��ɫţ��\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( who->get_legend(TASK_40,12) && !who->get_legend(TASK_40,13) ) 
		tmp += sprintf(ESC HIY "Ѱ������İ���\ntalk %x# welcome.1\n",getoid(this_object())); 

        send_user( who, "%c%s", ':', sprintf( "%s��\n    ������������Զû��ֹ�����ٻ�����Ҳֻ�ǹ������̣������������������ߣ�û��׷��ļ�ֵ��\n", get_name())
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
        int flag,i,size,p,amount;
        object who,item, *inv;     
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_legend(TASK_40,5) && !who->get_legend(TASK_40,6) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ս������������������Щƶ����գ���Ȼ����־��һ�����£����������������������ǣ�����Ҳ���������㣬ֻ����ô����û�������������գ�����¼�������������Ҳ��ʧ�ˣ���������һأ��Ҷ���Ϊ�����úŽǡ�\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_40,6) && !who->get_legend(TASK_40,7) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��ʵ�������ϴ�˵����֮�Žǲ���ֻ�Ǵ�˵��ֻ����֮�Žǵ��������̷ǳ����ӣ����ң�Ҳֻ��������ͨ�ĺŽǣ���ν���ͨ�ĺŽǼӹ�Ϊ�ܽ������ɵ���֮�Žǣ�����ֻ�������Ĺ����������õ���\n    ��Ȼ�������һ�����£��뼯����������������������գ�����Ҳ���������㣬ֻ�����Ѿ�����û�������Ž��ˣ�������¼�������������Ҳ��Ф��͵���ˣ��������Ѿ��ҵ��ң������㲻���;���ϣ�������ȥФ�������ж����򽻸��Ұɡ������ڶ������Ķ�����壬�����Ǽ����ݶ��Աߡ�\n"ESC"��������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_40,7) && !who->get_legend(TASK_40,8) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���û�м�¼���������������������������ζ��벻����Щ���ӵ����������ˡ�\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_40,8) && !who->get_legend(TASK_40,9) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������Žǿ���̫���ˣ�ʵ��������һ��ܸ��ӵĹ��գ������һ���Ҫһ��ԭ���ϲ��ܿ�ʼ������\n"ESC"�������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_40,9) && !who->get_legend(TASK_40,10) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��Ȼ���Ѿ�����¼�����ŽǷ�������򽻸����ˣ�������������������֮�ŽǵĺŽ���һ�����������Ʒ�������һ���Ҫһ�������ԭ���ϡ�����ɫţ�ǣ���������ý�ɫţ���ƳɵĺŽ��ǲ����ܼӹ�Ϊ��֮�Žǵģ�����Ҫ�����Ĺ�������ӹ�����֮�Žǣ���Ϊ����������ͱ����ҵ���ɫţ�ǣ�\n    ��ɫţ�Ǳ��ǽ�ţ֮�ǣ���������һ��ͻ�������ı�ʣ���Щ�����Ӳӵ�ţһҹ֮��ȫ�����У���ԭ�������ţ������һ��Ŀ�����Ϊ�˵�����Ⱥ��ţ���㽫���ǵĽ��ղ�����������ȥ֣������취�ҿ���Ҫ����Щ��ɫţ�ǰɡ���˵���ǰ�ţ�Ǳ����úܺã���װ����ҩ�������װ�š�\n"ESC"��������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_40,10) && !who->get_legend(TASK_40,11) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    û�н�ɫţ�ǣ��Ҳ��ܸ��������ܼӹ�����֮�ŽǵĺŽǣ����Լ����Ű�ɡ�\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_40,11) && !who->get_legend(TASK_40,12) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���˼�¼����������������ոմ����Ľ�ţ֮�ǣ������Һܿ�������ɺŽ��ˣ����Ժ��ٹ�������ȡ�Žǰɡ�\n"ESC"�������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_40,12) && !who->get_legend(TASK_40,13) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ڣ��ҰѺŽǽ����㣬������Ҫ�ǵã��ҽ�����ĺŽǲ����ǽ����õ���֮�Žǣ���Ҫ�õ������õ���֮�Žǣ�����Ҫ������͢�����ļӹ���������Ӧ��ȥ�������ǹ��ҵ����������ܲ��ܰ����㣬����˵����һ�����������ˣ�֧�������������������������Ȼ������ĳ�����ң���һ��������ġ�\n    ȥ�ɣ�ȥ�����ǹ��ҵ�������������������ɣ�������ֻ���ӣ�����װ�ľ��ǺŽǡ�\n"ESC"��������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),getoid(me)));

        	break;

        case 2:
        	if ( who->get_legend(TASK_40,5) && !who->get_legend(TASK_40,6) ) 
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_40,6);
			who->add_exp(3000);
			who->add_potential(100);
			who->add_cash(2500);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,10,"" );
			send_user(who,"%c%s",';',"����ĺŽ� ���� 3000 Ǳ�� 100 ��Ǯ 2500");
			me->do_welcome(1);
        	}
        	break;   
 	case 3:
        	if ( who->get_legend(TASK_40,6) && !who->get_legend(TASK_40,7) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_40,7);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"�ܹ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,11,"��ʧ�����" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��ʧ�����");
        	}
        	break;  
        case 4:
        	if ( who->get_legend(TASK_40,8) && !who->get_legend(TASK_40,9) ) 
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"���",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_40,9);
			who->add_exp(3500);
			who->add_potential(120);
			who->add_cash(3000);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,11,"" );
			send_user(who,"%c%s",';',"��ʧ����� ���� 3500 Ǳ�� 120 ��Ǯ 3000");
			me->do_welcome(1);
        	}
        	break;
 	case 5:
        	if ( who->get_legend(TASK_40,9) && !who->get_legend(TASK_40,10) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_40,10);
			who->delete_save("lysjinsnj");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"�ܹ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,12,"��ɫţ��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"��ɫţ��");
        	}
        	break;  
        case 6:
        	if ( who->get_legend(TASK_40,11) && !who->get_legend(TASK_40,12) ) 
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"װ��ɫţ�ǵ�����",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_40,12);
			who->delete_save("lysjinsnj");
			who->add_exp(3100);
			who->add_potential(105);
			who->add_cash(2700);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,12,"" );
			send_user(who,"%c%s",';',"��ɫţ�� ���� 3100 Ǳ�� 105 ��Ǯ 2700");
			me->do_welcome(1);
        	}
        	break;
 	case 7:
        	if ( who->get_legend(TASK_40,12) && !who->get_legend(TASK_40,13) )
        	{
			if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;        		
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			TASK_LEGEND_D->give_item(who,"item/98/0196",1); 
        		who->set_legend(TASK_40,13);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"�ܹ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,13,"Ѱ�����İ���" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"Ѱ�����İ���");
        	}
        	break;
        }
}