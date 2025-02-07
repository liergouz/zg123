/*-----------------------------------------------------------------------------------------*\
	《真假虎王》活动配置NPC ---- 活动天使
	由cjxx创建
	使用此文件时需要配合活动主控文件。
\*-----------------------------------------------------------------------------------------*/
#include <npc.h>
#include <ansi.h>

inherit SAVE_F;
inherit OFFICER;

#define GUESS_TRUE_TIGER	"/sys/party/guess_true_tiger"
#define _DEBUG(str) 		;//if(objectp(find_char("1"))) {tell_user(find_char("1"),str);}

void do_tiger_active(string arg);	//	真假虎王相关对话操作

int get_char_picid() { return 0951; }

void create() {
	set_name("活动天使");
	
	set_2("talk", ([
		"tiger" : (: do_tiger_active :),
	]));
	setup();
}

//	玩家点击NPC
void do_look(object who) {
	__FILE__->do_look_reflash(who,this_object());
}
//	do_look 的在线更新函数
void do_look_reflash(object who,object me) {
	int id = getoid(me);
	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf(
		"%s: \n 我是最最最最可爱的活动天使，隔壁的兑换天使比我丑多了～大话战国的活动都由我来负责，如果您有不清楚的地方，都可以来询问我哦～\n"
		ESC"真假虎王\ntalk %x# tiger.1\n"
		ESC"离开",me->get_name(),id
	));
}
//	调用下一关的函数
void play_next_stage(object who,int level) {
	GUESS_TRUE_TIGER->delete_tigers_on_player(who,0);
	GUESS_TRUE_TIGER->active_main_logic(who,level);
	who->set("now_call_out_next_stage",0);
}
//	玩家放弃活动
void give_up_the_activity(object who) {
	string *active_bonus,say_word;
	int level = who->get_save("guess_true_tiger");	
	if(level > 0) {
		active_bonus = active_bonus = GUESS_TRUE_TIGER->get_active_bonus(level);
		if(level > 1) {		
			say_word = sprintf("您闯关成功，将获得%s战国币与“"HIR"%s"NOR"”称号的奖励，请去活动兑换天使处领取奖励。",active_bonus[2],active_bonus[1]);
		} else {			
			say_word = sprintf("您闯关成功，将获得“"HIR"%s"NOR"”称号的奖励，请去活动兑换天使处领取奖励。",active_bonus[1]);
		}
		GUESS_TRUE_TIGER->delete_tigers_on_player(who,0);
		send_user(who,"%c%s",';',say_word);
		MAILBOX->sys_mail(who->get_id(),who->get_number(),say_word);
		who->delete("guess_true_tiger_map");
	} else {
		_DEBUG("DEBUG -- 错误！玩家没有得到闯关等级奖励!");
	}
}
//	隔段时间回调下一关
void call_out_next_stage(object who) {	
	string *active_bonus,say_word;
	int level = who->get_save("guess_true_tiger");
	if(level >=6) {
		active_bonus = active_bonus = GUESS_TRUE_TIGER->get_active_bonus(level);
		say_word = sprintf("您闯关成功，将获得%s战国币与“"HIR"%s"NOR"”称号的奖励，请去活动兑换天使处领取奖励。",active_bonus[2],active_bonus[1]);
		send_user(who,"%c%s",';',say_word);
		MAILBOX->sys_mail(who->get_id(),who->get_number(),say_word);		
	} else {
		if(get_z(who) == who->get("guess_true_tiger_map")) {
			if(who->get("guess_true_tiger_nojump")) {
				return;
			}
			GUESS_TRUE_TIGER->delete_tigers_on_player(who,0);
			if(!who->get("now_call_out_next_stage")) {
				send_user(who,"%c%s",'!',sprintf("5秒后将进入第%d关。",level+1));
				call_out("play_next_stage",5,who,level+1);
				who->set("now_call_out_next_stage",1);
			} else {
				who->add("define_tiger_attacking",1);
				if(who->get("define_tiger_attacking")>5) {
					play_next_stage(who,7);
					who->set("define_tiger_attacking",0);
				}
			}
		} else {
			_DEBUG("DEBUG -- 玩家已经不在活动场地");
			GUESS_TRUE_TIGER->delete_tigers_on_player(who,0);
			play_next_stage(who,7);
		}
	}
}
//	《真假虎王》过一关后的对白操作
void do_next_stage(object who) {
	__FILE__->do_next_stage_reflash(who,this_object());
}
//	do_next_stage 的在线更新函数
void do_next_stage_reflash(object who,object me) {
	int id = getoid(me);
	int level = who->get_save("guess_true_tiger");
	if(level>0) {
		if(level < 6) {
			send_user(who, "%c%s", ':',sprintf("您闯关成功，是否继续第 %d 关？如果失败，您将失去所有奖励，但是成功后的奖励是非常丰厚的。\n"
				ESC"继续\ndesc tiger_next\n"
				ESC"放弃\ndesc tiger_drop\n",level+1
			));
		} else {
			give_up_the_activity(who);
		}
	}
}
//	《真假虎王》相关对话操作
void do_tiger_active(string arg) {
	__FILE__->do_tiger_active_reflash(this_object(),arg);
}
//	《真假虎王》活动在线更新函数
void do_tiger_active_reflash(object me, string arg) {
	object who,*tmp_team;
	string say_word;
	int flag,id,level;
	who  = this_player();
	flag = to_int(arg);	
	id   = getoid(me);
	switch(flag) {
		case 1:	//	主对白
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s: \n真假虎王是一个过关类的活动，你可以在我这里了解详细情况。\n"
				ESC"活动详细说明\ntalk %x# tiger.2\n"
				ESC"参加活动\ntalk %x# tiger.3\n"
				ESC"离开",me->get_name(),id,id
			));
			break;
		case 2:	//	活动说明
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s: \n真假虎王活动需要你单独参加，不能够组队，收取10000战国币的门票费。\n    进入活动地图后，你面前会出现七只造型完全相同而能力不同的虎王，你可以挑选一只进行战斗，打败虎王则过一关。\n    第一关的七只虎王中有１只能力超强，剩下的６只都可以轻松打败，第二关的七只虎王中有２只能力超强，剩下的５只都可以轻松打败，以此类推，直到第六关的七只虎王中有６只能力超强，只剩下１只可以轻松打败。\n    如果你能连闯６关，那么你就可以得到至高无上的奖励，当然，你也可以中途放弃，那你将只能得到你当前过关的奖励，但是如果你在继续闯关的过程中失败了，那你将不会获得任何奖励。\n"
				ESC"离开",me->get_name()
			));
			break;
		case 3:	//	参加活动
			if(GUESS_TRUE_TIGER->is_in_active_area()) {
				level= who->get_save("guess_true_tiger");
				if(level >1) {
					say_word = "你上次闯关的奖励还没有领取，确定要再次进去挑战吗？这样会让你失去上次的奖励！";
				} else {
					say_word = "挑战虎王需要10000战国币的门票，你进活动场景后也可以让你的朋友来帮助你！";
				}
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s: \n%s\n"
					ESC"挑战\ntalk %x# tiger.4\n"
					ESC"离开",me->get_name(),say_word,id
				));
			} else {
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s: \n现在还不能参加真假虎王的游戏，%s 才是活动时间。\n"
					ESC"离开",me->get_name(),GUESS_TRUE_TIGER->get_active_time()
				));
			}
			break;
		case 4:	//	选择挑战
			if(GUESS_TRUE_TIGER->is_in_active_area()) {
				tmp_team = who->get_team();
				if(tmp_team != 0 && sizeof(tmp_team)>1) {
					send_user(who, "%c%s", '!', "您在队伍中，不能参加此次活动");
				} else {
					if(who->get_cash() >= 10000) {
						GUESS_TRUE_TIGER->active_main_logic(who,1);
					} else {
						send_user(who, "%c%s", '!', "您的战国币不够10000");
					}					
				}
			} else {
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s: \n现在还不能参加真假虎王的游戏，%s 才是活动时间。\n"
					ESC"离开",me->get_name(),GUESS_TRUE_TIGER->get_active_time()
				));				
			}
			break;
	}
}