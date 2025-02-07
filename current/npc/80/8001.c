
// �Զ����ɣ�/make/npc/make-biao

#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;
string *TalkTable = ({ 
        "����ͷ�������ҵģ����Ҹ����ʵı��ڶ������ס���",
        "���Ҿ����ھֻ���һ��������������˼Ҿ�Ȼû�ա���",
        "���Ҿ����ھֻ������ѷ��磬���������˼Ҿ�Ȼû�ա���",
        "�ܹ��ľ����ھ�ξ������ͷ���ո�ǿ�����Ժ�ˬ������һ���ú���",
});
void do_task_start();
void do_task_cancel();

// ��������ȡ��������
int get_char_picid() { return 5802; }
void do_welcome( string arg );

// ���������촦��
void create()
{
        set_name("����");
        set_city_name("���");

	set_2( "talk", ([
                "welcome"        : (: do_welcome :),
        ])); 
	set("mpLegend",([110:({32*44+24})]));
	set("mpLegend2",([0:({32*30+9,32*30+19,}),110:({32*44+26,}),]));
        setup();
}

// �������Ի�����
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
	if ( who->get_legend(TASK_30,8) && !who->get_legend(TASK_30,9) )
	{
		tmp += sprintf(ESC HIY "ѯ��ԭ��\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( who->get_legend(TASK_30,9) && !who->get_legend(TASK_30,10) )
	{
		tmp += sprintf(ESC HIY "�����Ƿ�\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( who->get_legend(TASK_30,18) && !who->get_legend(TASK_30,19) )
	{
		tmp += sprintf(ESC HIY "ѱ�����\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( (who->get_level() >=110 && !who->get_legend(TASK_44,24)) || (who->get_legend(TASK_44,24) && !who->get_legend(TASK_44,26)) )
		tmp += sprintf(ESC HIY "��������֮ͽ\ntalk %x# welcome.5\n",getoid(me));
	if ( who->get_legend(TASK_44,26) && !who->get_legend(TASK_44,27) ) 
		tmp += sprintf(ESC HIY "�Ͳ���\ntalk %x# welcome.5\n",getoid(me));

	send_user(who,"%c%s",':',sprintf( "%s��\n    %s\n", get_name(), TalkTable[ random(sizeof(TalkTable))] ) 
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
           
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_legend(TASK_30,8) && !who->get_legend(TASK_30,9) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����������ˣ�\n"ESC"�������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_30,9) && !who->get_legend(TASK_30,10) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �װ�������������̫�������ǵķ��Ӻ����ҵķ������ڣ�����Ȼ˵�Ҽҵ�����ռ�����ҵ��쾮��ǽ�ڽ�����һ�磬Ӳ�Ƕ��ֲ������Ǽҵ����ܣ��ҿ��˰��ǽ��������Ǽ��������©ˮ�������������Σ������޷�ס�ˣ�ֻ�ðᵽ�Ӷ԰�������ص���ʱ�����������ˣ���λ������ҪΪ��������ִ�԰���\n"ESC"��������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_30,18) && !who->get_legend(TASK_30,19) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ���ڿ��Բ��ؼ����Ǹ�С�����ˣ������£��Ⱳ��û���������������������ٱ��ɣ�\n"ESC"�������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
        case 2:
        	if ( who->get_legend(TASK_30,8) && !who->get_legend(TASK_30,9) )
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_30,9);
			who->add_exp(62000);
			who->add_potential(770);
			who->add_cash(53000);
			send_user(who,"%c%s",';',"ѯ��ԭ�� ���� 62000 Ǳ�� 770 ��Ǯ 53000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,35,"" );
			me->do_welcome(1);
        	}
        	break;
        case 3:
        	if ( who->get_legend(TASK_30,9) && !who->get_legend(TASK_30,10) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_30,10);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,36,"�����Ƿ�" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�����Ƿ�");
        	}
        	break; 
        case 4:
        	if ( who->get_legend(TASK_30,18) && !who->get_legend(TASK_30,19) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;
			TASK_LEGEND_D->task_finish(who);
			TASK_LEGEND_D->give_item(who,"item/final/91/1812",2);
			who->set_legend(TASK_30,19);
			who->add_exp(68000);
			who->add_potential(800);
			who->add_cash(51000);
			send_user(who,"%c%s",';',"ѱ����� ���� 68000 Ǳ�� 800 ��Ǯ 51000 �Ͻ� 2");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,39,"" );
        	}
        	break;
        case 5:
        	if ( who->get_level() >= 110 && !who->get_legend(TASK_44,24)  )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����뵱����Ҳ���������ݵĽ�����������һ����Ӧ���ò���⣬�벻�������黢�����������Ϻ�ɫ�ľ��������޿��κΣ��������ҵ�С檶�����Ȼ�������ɽ����������������Ѿ�һ�����У���û�ˣ���������Щ����Ҳ����Ź�������ң��������ν���ҳϣ���ν�����飬�����ȥ�ɵ���Щ��������ļһ�ɣ�ʲô����˵������������������������ģ���͸��Ҹɵ�����Щ���������������ǹ�꣬ʲô������ô���з���������£��ѵ��㲻֪������ΰ���Ԧ��ʦ����Ȼ�ҷ��������ˣ������һ����ܹ�֪��������ʲô�ط������������棬����Ҹɵ��ֵ����׵�10����������֪���������ҵ��³���\n"ESC"��������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_44,24) && !who->get_legend(TASK_44,25) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �һ���Ϊ��һ���������ǿ����и����ε��ˣ����ԭ�������󱲣������������ߣ��������ٴο����ˣ�\n"ESC"�뿪", me->get_name()));
        	else if ( who->get_legend(TASK_44,25) && !who->get_legend(TASK_44,26) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������������������Ŀ����,״�����,���������������˵Ĵ���,��׳�ŵ���,������߬��������������,�Ͻ����ˡ���\n"ESC"�������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_44,26) && !who->get_legend(TASK_44,27) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��һ���Ƕ�Թ�������������˱��˸��ҵ��˺������Ӳ������Ǳ��˶��ҵĶ��ݡ�ǰ��ʱ�������˽�ͷ��ʱ���������������Ҹ���һ������֮������Ҫ֪����������֮���ܾ����۵��Ҽ�ֱ�����������찡��Ҳ����Ҷ�����û����ȫ�����������ҵ����л�����ôһ�����ů�������޳��Ҳ��������ʲô���صĶ�����ֻ����˵���������������������Ҫ�������Ͳ��ѣ������ϵ���������֪��������������Щ���ꡢ���ꡢǹ��ϲ���ռ����ֶ�����ֻ���������ȥ�ҵ������������ı����⡣\n"ESC"��������\ntalk %x# welcome.8\n"ESC"�뿪", me->get_name(),getoid(me)));
        	break;
        case 6:
        	if ( who->get_level() >= 110 && !who->get_legend(TASK_44,24)  )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_44,24);
        		who->delete_save("lituqianhun");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,66,"������ů��1��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"������ů��1��");
        	}
        	break;
	case 7:
        	if ( who->get_legend(TASK_44,25) && !who->get_legend(TASK_44,26) )
        	{
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_44,26);
        		who->delete_save("lituqianhun");
			who->add_exp(51000);
			who->add_potential(778);
			who->add_cash(50300);
			send_user(who,"%c%s",';',"������ů��1�� ���� 51000 Ǳ�� 778 ��Ǯ 50300");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,66,"" );
			me->do_welcome(5);
        	}
        	break; 
        case 8:
        	if ( who->get_legend(TASK_44,26) && !who->get_legend(TASK_44,27) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_44,27);
        		who->delete_save("lituyoucaizi");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_QIGUO,"���" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_QIGUO,67,"������ů��2��" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"������ů��2��");
        	}
        	break;
        }
}
