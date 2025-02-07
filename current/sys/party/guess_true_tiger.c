/*----------------------------------------------------------------------------------------*\
	¡¶Õæ¼Ù»¢Íõ¡·µÄ»î¶¯Ö÷¿ØÎÄ¼ş£º
	±¾»î¶¯ÖÁÉÙÊ¹ÓÃÁË smart_alarm_clock ¿Ø¼ş ºÇºÇ£¬
	ÓÉ cjxx ´´½¨
	Ô¤¼ÆÍê³ÉÊ±¼ä 2007-07-16 P18:00
	¹¦ÄÜ£º
		»î¶¯¡¶Õæ¼Ù»¢Íõ¡·µÄÖ÷ÒªÂß¼­¿ØÖÆ¶¼ÔÚÕâ¸öÀïÃæ£¬ÊÇÒ»¸ö¾ø¶Ô»ìÂÒºÍ¼¯ÖĞÔÓºÏÌå
	ÏêÏ¸ÎÄµµ²Î¼û¡¶Õæ¼Ù»¢Íõ»î¶¯¿ª·¢ÎÄµµ¡·
\*----------------------------------------------------------------------------------------*/
#include <ansi.h>
#include <public.h>
#include <effect.h>
#include <skill.h>
#include <smart_alarm_clock.h>

inherit SAVE_F;

#define _DEBUG(str) 		;//if(objectp(find_char("1"))) {tell_user(find_char("1"),str);}
#define AUTO_REMOVE_ANGEL	1						//	ÊÇ·ñ×Ô¶¯ÔÚ¹Ø±Õ»î¶¯Ê±×Ô¶¯Çå³ı¡°»î¶¯ÌìÊ¹¡±
#define LOCK_PLAYER_DAMAGE	100000						//	ÉèÖÃÃ¿´Î¶ÔÍæ¼ÒµÄ¹Ì¶¨ÉËº¦Öµ
#define SMART_ALARM_CLOCK_F	"/inh/clock/smart_alarm_clock"			//	Ê¹ÓÃÄÖÖÓ²¿·Ö¹¦ÄÜº¯Êı
#define ACTIVE_ANGEL_NPC	"npc/party/gtt_active_angel"			//	»î¶¯ÌìÊ¹´æ·ÅÎ»ÖÃ
#define TIGER_KING_NPC		"npc/party/gtt_tiger_king"			//	Õæ¼Ù»¢Íõ´æ·ÅÎ»ÖÃ
#define TEMP_WORKER_NPC		"npc/party/gtt_temp_worker"			//	ÁÙÊ±´«ËÍ¹¤´æ·ÅÎ»ÖÃ
#define VIRTUAL_MAP		"inh/std/normal"				//	ĞéÄâµØÍ¼Î»ÖÃ

/*-----------------------------------¡¶Õæ¼Ù»¢Íõ¡·»î¶¯Ïà¹Ø±äÁ¿ÉèÖÃ-----------------------------*/
private int active_time_from	= 50900;				//	»î¶¯ÆğÊ¼Ê±¼äÕûÊı
private int active_time_to	= 60000;				//	»î¶¯½áÊøÊ±¼äÕûÊı
private int active_is_open	= 0;					//	»î¶¯¿ªÆô±êÖ¾

private static mapping active_bonus = ([				//	»î¶¯½±ÀøÄÚÈİ½á¹¹
	1:({"A013","Ò»ÂíÆ½´¨"    , "0"}),
	2:({"A014","¶şÁúÏ·Öé"    , "5,000"}),
	3:({"A015","ÈëÄ¾Èı·Ö"    , "10,000"}),
	4:({"A016","åÛÓÎËÄº£"    , "100,000"}),
	5:({"A017","ÎäËÉ´ò»¢"    , "450,000"}),
	6:({"A018","¹ıÎå¹ØÕ¶Áù½«", "1,000,000","Îï·À+10£¬·¨·À+10£¨³ÆºÅÊôĞÔĞèÍæ¼ÒÔÚ×°±¸³ÆºÅºó²ÅÆğ×÷ÓÃ£©"}),
]);
private static int *left_tiger_position = ({35,31});
private static int pro_tiger_distance   = 2;
/*------------------------------------------Íê±Ï----------------------------------------------*/

/*--------------------------------------¹«ÓĞº¯Êı½Ó¿Ú------------------------------------------*/
int turn_on_activity();							//	¿ªÆô»î¶¯µÄ¹¦ÄÜº¯Êı -- ³É¹¦·µ»Ø1 Ê§°Ü 0
int turn_off_activity();						//	¹Ø±Õ»î¶¯µÄ¹¦ÄÜº¯Êı -- ³É¹¦·µ»Ø1 Ê§°Ü 0
int set_active_time(int from,int to);					//	ÉèÖÃ»î¶¯Ê±¼äĞèÒªÁ½¸öÕûĞÍ²ÎÊı [0-6][00-23][00-59]
int active_main_logic(object who,int level);				//	¡¶Õæ¼Ù»¢Íõ¡·»î¶¯µÄÖ÷Âß¼­Ú	
int is_active_open();							//	ÅĞ¶Ïµ±Ç°»î¶¯µÄ¿ªÆô×´Ì¬
int is_in_active_area();						//	ÅĞ¶Ïµ±Ç°Ê±¼äÊÇ·ñÔÚ»î¶¯Ê±¼ä·¶Î§ÄÚ
void delete_tigers_on_player(object who,int act);			//	Çå³ıµôÍæ¼ÒÉíÉÏËù¶ÔÓ¦µÄ»¢Íõ±ê¼Ç
void when_player_dead(object who);					//	µ±Íæ¼ÒËÀÍöÊ±Ö´ĞĞµÄº¯Êı
void when_enemy_be_hit(object me,object who,int hit_act,int distance);	//	µ±Íæ¼Ò±»¹¥»÷Ê±ËùÖ´ĞĞµÄº¯Êı
string get_active_time();						//	»ñÈ¡µ±Ç°ÒÑ¾­Éè¶¨ºÃµÄ»î¶¯Ê±¼ä
string *get_active_bonus(int level);					//	»ñÈ¡¹ı¹ØµÈ¼¶Ëù¶ÔÓ¦µÄ½±ÀøÊı×é
/*------------------------------------------Íê±Ï----------------------------------------------*/

/*----------------------------------------³õÊ¼º¯Êı--------------------------------------------*/
void SAVE_BINARY() {}
string get_save_file() {
	return "data/guess_true_tiger"SAVE_EXTENSION;
}
void create() {
	restore();
	if(active_is_open) {
		turn_on_activity();
	} else {
		turn_off_activity();
	}
}
/*------------------------------------------Íê±Ï----------------------------------------------*/

/*-----------------------------------------Ë½ÓĞº¯Êı-------------------------------------------*/
//	·µ»ØÒ»¸ö·¶Î§²»ÖØ¸´ÂÒĞòµÄÕûÊıÊı×é-- ÕâÀï¼Ù¶¨ÂÒĞòÊı×ÖÊÇÒ»¸öÁ¬ĞøÕûÌåÇÒ¼ä¸ôÎª1
private int *make_only_number(int from,int to) {
	int *original_dict=({});
	int *result_dict=({});
	int tmp,i,size;
	if(from > to) {
		tmp = to;
		to  = from;
		from= tmp;
	}
	for(i=0,size=(to-from);i<size;i++) {
		original_dict += ({from+i});
	}
	for(i=0;i<size;i++) {
		tmp = random(to-from-i);
		result_dict   += ({original_dict[tmp]});
		original_dict -= ({original_dict[tmp]});
	}
	return result_dict;
}
//	Éú³É»î¶¯ÌìÊ¹
private object *invite_active_angel(int num) {
	object *active_angels = ({});
	for(int i=0;i<num;i++) {
		active_angels += ({new(ACTIVE_ANGEL_NPC)});
		_DEBUG("DEBUG --Éú³ÉÒ»¸ö");
	}
	return active_angels;
}
//	Éú³É»¢Íõ
private object *invite_tiger_kings(int number,int strong,int week) {
	object *tiger_kings = ({});
	object tmp_tiger_king;
	int i,*only_int_number,total;
	total = strong+week;
	only_int_number = make_only_number(0,total);
	for(i=0;i<total;i++) {
		if(only_int_number[i]<strong) {
			//	ÉèÖÃ½ÏÇ¿»¢ÍõµÄÊôĞÔ
			tmp_tiger_king = new(TIGER_KING_NPC);
			tmp_tiger_king->set_walk_speed(1);
	        	tmp_tiger_king->set_walk_step(2);
	        	tmp_tiger_king->set_max_seek(8);
			tmp_tiger_king->set_attack_speed(10);
			tmp_tiger_king->set_dp(50000);
			tmp_tiger_king->set_pp(50000);
			tmp_tiger_king->set_max_hp(100000);
			tmp_tiger_king->set_max_mp(100000);
			tmp_tiger_king->set_ap(100000);
			tmp_tiger_king->set_cp(100000);
			tmp_tiger_king->set_when_enemy_dead((:when_player_dead:));
			tmp_tiger_king->set_when_enemy_be_hit((:when_enemy_be_hit:));
			tmp_tiger_king->set("enemy",number);
			tiger_kings += ({tmp_tiger_king});
		} else {
			//	ÉèÖÃ½ÏÈõ»¢ÍõµÄÊôĞÔ
			tmp_tiger_king = new(TIGER_KING_NPC);
			tmp_tiger_king->set_walk_speed(20);
			tmp_tiger_king->set_attack_speed(20);
			tmp_tiger_king->set_max_hp(10);
			tmp_tiger_king->set_max_mp(10);
			tmp_tiger_king->set_ap(10);
			tmp_tiger_king->set_dp(10);
			tmp_tiger_king->set_cp(10);
			tmp_tiger_king->set_pp(10);
			tmp_tiger_king->set("enemy",number);
			tmp_tiger_king->set_when_enemy_dead((:when_player_dead:));
			tiger_kings += ({tmp_tiger_king});
		}
	}
	return tiger_kings;
}
//	ÎŞÌõ¼şÇå³ıNPCs
private int byebye_npcs(object *npcs) {
	int i,size;
	for(i=0,size=sizeof(npcs);i<size;i++) {
		if(objectp(npcs[i]) && get_x(npcs[i])>0) {
			npcs[i]->remove_from_scene();
			destruct(npcs[i]);
		} else {
			_DEBUG(sprintf("DEBUG -- Çå³ı²»ÁË %x#",getoid(npcs[i])));
		}
	}
	npcs = ({});
	return 1;
}
//	²úÉúÒ»¸öÓĞĞ§µÄµØÍ¼Î»ÖÃ
private int get_valid_xy_point(int z) {
	int p,i;
	for(i=0,p=0;i<50;i++) {
		if(p = efun::get_xy_point(z, IS_CHAR_BLOCK)) {
			return p;
		}
	}
}
/*-------------------------------------------Íê±Ï---------------------------------------------*/

/*-----------------------------------------¹«ÓĞº¯Êı-------------------------------------------*/
//	¿ªÆô»î¶¯
int turn_on_activity() {
	object *active_angels = children(ACTIVE_ANGEL_NPC);
	int size_active_angels= sizeof(active_angels);	
	if(size_active_angels < 3) {
		if(size_active_angels > 0) {
			_DEBUG("DEBUG -- Çå³ıÒÑ¾­Éú³ÉµÄ»î¶¯ÌìÊ¹");
			byebye_npcs(active_angels);
		}
		active_angels = invite_active_angel(3);
		if(sizeof(active_angels) < 3) {
			_DEBUG("DEBUG -- »î¶¯ÌìÊ¹Éú³É´íÎó~");
			return 0;
		}
		active_angels[0]->add_to_scene(1,152,129);
		active_angels[1]->add_to_scene(4,152,129);
		active_angels[2]->add_to_scene(7,152,129);
	}
	active_is_open = 1;
	save();
	_DEBUG("DEBUG -- ³É¹¦¿ªÆô»î¶¯£¡");
	return 1;
}
//	¹Ø±Õ»î¶¯
int turn_off_activity() {
	object *active_angels;
	if(AUTO_REMOVE_ANGEL) {
		active_angels = children(ACTIVE_ANGEL_NPC);
		if(sizeof(active_angels)) {
			byebye_npcs(active_angels);
		}		
	}
	active_is_open = 0;
	_DEBUG("DEBUG -- ³É¹¦¹Ø±Õ»î¶¯£¡");
	save();
	return 1;
}
//	ÅĞ¶Ïµ±Ç°Ê±¼ä»î¶¯ÊÇ·ñ¿ÉÒÔ¿ªÆô ¿ÉÒÔ·µ»Ø1 ·ñÔò·µ»Ø0
int is_in_active_area() {
	int next_from,next_to;
	if(!active_is_open) {
		_DEBUG("DEBUG -- µ±Ç°»î¶¯¿ª¹Ø´¦ÓÚ¹Ø±Õ×´Ì¬£¡");
		return 0;
	}	
	if(!next_from= SMART_ALARM_CLOCK_F->find_next_time_stamp("week",sprintf("%05d",active_time_from),"minute")) {
		_DEBUG("DEBUG -- È¡ÆğÊ¼Ê±¼äÊ±³öÏÖ´íÎó£¡");
		return 0;
	}
	if(!next_to  = SMART_ALARM_CLOCK_F->find_next_time_stamp("week",sprintf("%05d",active_time_to),"minute")) {
		_DEBUG("DEBUG -- È¡½áÊøÊ±¼äÊ±³öÏÖ´íÎó£¡");
		return 0;
	}
	return next_from > next_to ? 1:0;
}
//	ÅĞ¶Ïµ±Ç°¡¶Õæ¼Ù»¢Íõ¡·ÊÇ·ñ´¦ÓÚ¿ªÆô×´Ì¬
int is_active_open() {
	return active_is_open;
}
//	ÉèÖÃ»î¶¯Ê±¼ä ³É¹¦·µ»Ø1 Ê§°Ü·µ»Ø 0
int set_active_time(int from,int to) {
	active_time_from= from % 70000;
	active_time_to 	= to   % 70000;
	_DEBUG(sprintf("DEBUG -- ÉèÖÃÊ±¼ä´Ó %05d µ½ %05d ",active_time_from,active_time_to));		
	save();	
	return 1;
}
//	»ñÈ¡µ±Ç°µÄ»î¶¯Ê±¼ä
string get_active_time() {
	string *week_day = ({"ÈÕ","Ò»","¶ş","Èı","ËÄ","Îå","Áù"});;
	return sprintf("Ã¿ÖÜ%s %02d:%02d-%02d:%02d",week_day[active_time_from/10000],active_time_from%10000/100,active_time_from%100,active_time_to%10000/100 == 0 ? 24 :active_time_to%10000/100,active_time_to%100);
}
//	»ñÈ¡Ä³µÈ¼¶ËùÓ¦»ñµÃµÄ¾­Ñé½±Àø
string *get_active_bonus(int level) {
	level = level > 6 ? 6 : level < 1 ? 1 : level;
	return active_bonus[level];
}
//	Çå³ıµôÍæ¼ÒÉíÉÏËù¶ÔÓ¦µÄ»¢Íõ±ê¼Ç
void delete_tigers_on_player(object who,int act) {
	mixed tigers_id;
	object item;
	int i,size;
	tigers_id = who->get("guess_true_tiger_tigers");
	for(i=0,size=sizeof(tigers_id);i<size;i++) {
		if(item = find_char(tigers_id[i])) {
			if(item->is_npc()) {
				item->remove_from_scene(act);
			        item->before_destruct();
				destruct(item);
			} else {
				_DEBUG(sprintf("DEBUG -- »¢Íõ %s ²»ÊÇNPC",tigers_id[i]));
			}
		} else {
			_DEBUG(sprintf("DEBUG -- Ã»ÓĞÕÒµ½¶ÔÓ¦¶ÔÏó %s ",tigers_id[i]));
		}
	}
	who->delete("guess_true_tiger_tigers");
	who->delete_save("guess_true_tiger_fight");
}
//	µ±Íæ¼Ò±»´òËÀÊ±ËùÖ´ĞĞµÄº¯Êı
void when_player_dead(object who) {
	int old_z;
	object old_city;
	send_user(who,"%c%s",'!',"ºÜÒÅº¶£¬Äã´³¹ØÊ§°ÜÁË£¬²»ÄÜ»ñµÃÈÎºÎ½±Àø¡£");
	if((old_z = who->get("guess_true_tiger_map")) && (get_z(who) == old_z)) {
                old_city = get_map_object(old_z);                
       		VIRTUAL_MAP->destruct_virtual_map(old_city, old_z);
	}
	who->add_to_scene(1, 152, 130, 3);
	who->delete_save("guess_true_tiger");
	who->delete("guess_true_tiger_map");
	//who->set_save("userkill",1);
	//who->set_die(1);
	delete_tigers_on_player(who,0);
}
//	µ±Íæ¼ÒÊÜµ½¹¥»÷Ê±ËùÖ´ĞĞµÄº¯Êı
void when_enemy_be_hit(object me,object who,int hit_act,int distance) {
	send_user( who, "%c%d%w%c%d%w%c", 0x48, getoid(who), LOCK_PLAYER_DAMAGE, get_d(who), getoid(me),hit_act, hit_act == HIT_NORMAL ? 2 : 1 );
	CHAR_DIE_D->is_enemy_die(me, who, LOCK_PLAYER_DAMAGE);
}
//	¿ªÊ¼ÓÎÏ· -- ´Ë´Î»î¶¯µÄÖ÷Âß¼­º¯Êı
int active_main_logic(object player,int level) {
	object map,old_city,temp_worker;
	object *tiger_kings = ({});
	int x,y,z,d,size,i,p,old_z,*only_random_number;
	player->set("guess_true_tiger_nojump",1);
	switch(level) {
		case 1:
			if( ( z = find_map_flag(1000, 2999, 0) ) <= 0 ) {
				return 1;
			}
			player->delete_save("guess_true_tiger");
			player->delete_save("guess_true_tiger_fight");
			player->set("guess_true_tiger_tigers",({}));
			player->set("guess_true_tiger_map",z);
			d = 891;
			init_virtual_map(z,d);
			map = new(VIRTUAL_MAP);
			map->set_client_id(d);
			map->set_owner(player);
			map->set_name("¡°Õæ¼Ù»¢Íõ¡±»î¶¯³¡");
			set_map_object(map,map->set_id(z));
			tiger_kings = invite_tiger_kings(player->get_number(),1,6);
			size = sizeof(tiger_kings);
			only_random_number = make_only_number(0,size);
			for(i=0;i<size;i++) {
				p = get_valid_xy_point(z);
				tiger_kings[only_random_number[i]]->add_to_scene(z,p/1000,p%1000,3);
				//tiger_kings[only_random_number[i]]->add_to_scene(z,left_tiger_position[0]+i*pro_tiger_distance,left_tiger_position[1],3);
				player->add("guess_true_tiger_tigers",({sprintf("%x#",getoid(tiger_kings[i]))}));
			}
			temp_worker = new(TEMP_WORKER_NPC);
			temp_worker->add_to_scene(z,36,40,5);
			p = get_valid_xy_point(z);
			player->add_to_scene(z,p/1000,p%1000,3);
			player->add_cash(-10000);
			break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			tiger_kings = invite_tiger_kings(player->get_number(),level,7-level);
			size=sizeof(tiger_kings);
			only_random_number = make_only_number(0,size);
			player->set("guess_true_tiger_tigers",({}));
			z = player->get("guess_true_tiger_map");
			for(i=0;i<size;i++) {
				p = get_valid_xy_point(z);
				tiger_kings[only_random_number[i]]->add_to_scene(z,p/1000,p%1000,3);
				//tiger_kings[only_random_number[i]]->add_to_scene(player->get("guess_true_tiger_map"),left_tiger_position[0]+i*pro_tiger_distance,left_tiger_position[1],3);
				player->add("guess_true_tiger_tigers",({sprintf("%x#",getoid(tiger_kings[i]))}));
			}
			break;
		case 7:
			if((old_z = player->get("guess_true_tiger_map")) && (get_z(player) == old_z)) {
	                        old_city = get_map_object(old_z);
		                player->add_to_scene(1, 152, 130, 3);
	        		VIRTUAL_MAP->destruct_virtual_map(old_city, old_z);
			}
			break;
	}
	return 1;
}
/*-------------------------------------------Íê±Ï---------------------------------------------*/
/*-------------------------------------------µ÷ÊÔ---------------------------------------------*/
/*-------------------------------------------Íê±Ï---------------------------------------------*/