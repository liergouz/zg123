#include <npc.h>
#include <ansi.h>
#include <time.h>

inherit OFFICER;
// 函数：获取人物造型
int get_char_picid() { return 5109; }
void do_welcome(string arg);

// 函数：构造处理
void create()
{
        set_name("无双城守卫");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
        ]) );
        setup();
}

void do_look(object who) { __FILE__->do_look_call(this_object(),who); }

void do_look_call(object me,object who)
{
	int id = getoid(me);

	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    无双之城，举世无双！无双城乃是实力和地位的象征！如果能当上无双城主，那将是一份莫大的荣耀！呵呵～你想进去看一下吗？\n"
//	ESC"进入无双城\ntalk %x# welcome.101\n"
	ESC"了解攻城规则\ntalk %x# welcome.104\n"
	ESC"近期攻城帮会查询\ntalk %x# welcome.107\n"
	ESC"离开",me->get_name(),id,id));
}


void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag, p,i,size,id,iTime,amount;
       	object who, item,*nTeam;
	  
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
//        case 101:
//        	WUSHUANG->trans_into_wushuang(me,who);
//        	break;	
        case 104:
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s：\n    想攻占无双城吗？那就仔细听一下规则：\n    1.攻城须以帮会形式存在，帮主须前去周王处提交攻城申请。\n    2.申请提交结束之后，任何玩家均可来我这里查询攻城日期（攻城日期为：以申请攻城之日为基准，向后延退两日）。\n    3.攻城开启时间为：每晚7：30——9：00（前提是：攻城方须提前两日申请）。\n    4.攻城胜利判断标志：哪一方将无双宫内，非本帮会玩家全部清除出去，此时由帮主与宫内官员对话，便可成功攻占无双之城。\n    5.处在攻城区域内的玩家，全部默认为帮派保护模式，即：非本帮会成员，一律可将其击杀。\n    不过还须注意一点：在攻城时间未结束时，被攻方还有可能返攻回来哦～！\n"ESC"离开", me->get_name(), ) );
        	break;	
        case 107:
        	WUSHUANG->attack_list(me,who);
        	break;	
        	
        	
        }

}