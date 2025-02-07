#include <npc.h>
#include <ansi.h>
#include <time.h>

inherit OFFICER;
// 函数：获取人物造型
int get_char_picid() { return 5502; }
void do_welcome(string arg);
// 函数：构造处理
void create()
{
        set_name("无双城官员");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
        ]) );
        setup();
}

void do_look(object who) { __FILE__->do_look_call(this_object(),who); }

void do_look_call(object me,object who)
{
	int id = getoid(me);

	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    本官员负责打理无双城大小一切事物，请问你找本官有何贵干？\n"ESC"申请占领无双城\ntalk %x# welcome.64\n"ESC"查询当前税金\ntalk %x# welcome.888\n"ESC"领取税金\ntalk %x# welcome.889\n"ESC"离开",me->get_name(),id,id,id));
}


void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag, p,i,size,id,iTime,amount,duty;
       	object who, item,*nTeam;
	string tmp;
        who = this_player();
	if ( arg && sscanf(arg,"%d.%s",flag,tmp) != 2 )
		flag = to_int(arg);
	id = getoid(me);
//        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 64:
        	WUSHUANG->occupy_city(me,who);
        	break;	

        case 888:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    当前税金为（%d）\n",me->get_name(),WUSHUANG->get_save("wg_duty")));
        	break;	
        case 889:
		if (who->get_org_name()==WUSHUANG->get_save_2("occupy_org") && who->get_org_position()>7)
			send_user( who, "%c%c%d%s", '?', 16, 8, sprintf("请输入要领取的税金数量：（当前可领取%d）\n",WUSHUANG->get_save("wg_duty"))+sprintf( ESC"talk %x# welcome.890",id)+".%s\n" );
		else
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你不符合领取税金条件，领取税金的条件是：必须是无双城帮派的帮主或副帮主。\n"ESC"离开",me->get_name()));
        	break;	
	case 890:
		duty = to_int( tmp );
		if ( duty > WUSHUANG->get_save("wg_duty") )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    本官可没有收到这么多税哦！\n"ESC"离开",me->get_name()));
			return;
		}
		if (who->get_org_name()==WUSHUANG->get_save_2("occupy_org") && who->get_org_position()>7)
		{
			if ( duty > WUSHUANG->get_save("wg_duty") ) duty = WUSHUANG->get_save("wg_duty");
			who->add_cash(duty);
//			who->log_money("领无双城税金", duty);
log_file("wu_duty.dat", sprintf("%s %s(%d) 领税金 %d\n", short_time(), who->get_id(), who->get_number(), duty));
			WUSHUANG->add_save("wg_duty",-duty);
			WUSHUANG->save();
			send_user(who,"%c%s",';',sprintf("你领取了"HIR" %d "NOR"税金",duty));
		}
        	break;
        }

}