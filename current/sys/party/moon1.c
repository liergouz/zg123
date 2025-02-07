/*******************************
	**ÖĞÇï»î¶¯**
*******************************/
#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <public.h>
#include <time.h>
#include <action.h>
#include <skill.h>
inherit DBASE_F;
inherit SAVE_F;
#define DEBUG_STR(player,str) {tell_user(player,"str=%s",str);}

#define YUEBING	"item/04/mooncake"//Õâ¸öµ½Ê±ºòÒª¸Ä»ØÈ¥µÄ£¬ÏÈ×¢ Ò»ÏÂ¡£
#define YUEHUAN "item/04/0454"//ÔÂ»·¡£
//#define YUTU	"npc/party/yutu"
#define YUTU	"npc/party/0008"
int iStart,iFinish,iFinish_a,kkkk,close;
//object* nObjs= ({});//±£´æÍæ¼ÒµÄĞÅÏ¢ÒÔ±ã·ÃÎÊÉ¾³ıÍÃ×ÓµÄÊıÁ¿¡£
object change;
string *nWord = ({
	"ÈÃ×îÔ²µÄÃ÷ÔÂÅã°éÄãºÍÎÒ£¬ÈÃÃ÷ÔÂ´«´ïÎÒµÄĞÄÔ¸ºÍ×£¸£¡£×££¬ÖĞÇï¿ìÀÖ£¬ÔÂÔ²ÈËÔ²ÊÂÊÂÔ²¡£",
	"Ìıµ½~Ïëµ½~ĞÄµ½£¬Ëµµ½~×öµ½~µÃµ½£¬Ê±¼äµ½£¬ÎÒµÄÃÀºÃ×£¸£ºÍË¼ÄîÒÑ¾­È«ÈÃÄãÊÕµ½¡£",
	"ÎÒµÄĞÄÔÚ¼üÅÌÉÏ£¬µÈÄãÀ´ÇáÇáµÄÇÃ»÷¡£ÌìÉÏµÄÔÂ£¬µÈÓĞÇéÈËÀ´¼ÄÍû£¬ÖĞÇïµÄÒ¹ÍíÎÒ½«Ã÷ÔÂºÍĞÇĞÇÅÅ³É×îÃÀµÄ×£¸££ºÖĞÇï¿ìÀÖ¡£",
	"ÎÒÀãÀãµÄ¿´×ÅÖĞÇïµÄÔÂÁÁ£¬·Â·ğËüÊÇÒ»ÃæÃ÷¾µ£¬ÄãÎÒÔÚ»¥Ïà×¢ÊÓÃàÃàË¼ÒâºÍ×£¸£¡£",
	"ÎÒ½«ÄãµÄIDºÅÂë¸æËßÁËÒ»¸öÄ°ÉúÈË£¬Ëû½ĞÔÂÀÏ£¬Ëû»áÔÚÖĞÇïÔÂÔ²Ò¹Òª°ïÎÒ¸æËßÄã£¬ÎÒË¼ÄîÄã¡£",
	"Ô¶·½µÄÅóÓÑÄãÊÇ·ñÎŞí¦£¿ÔÚÕâ¸öË¼ÄîµÄ¼¾½ÚÀï£¬¸Ä±äµÄÎÒµÄÈİÑÕ£¬²»±äµÄÓÀÔ¶µÄÇ£¹ÒÄãµÄĞÄ£¡",
	"ÔÂÈ±Ê±ÎÒÏëÄã£¬ÔÂÔ²Ê±ÎÒÄîÄã£¬ÎŞÂÛÔÂÔ²ÔÂÈ±£¬ÎÒµÄĞÄÈçÄÇºã¹Å²»±äµÄÔÂÁÁÄ¬Ä¬×·Ëæ×Å×£¸£Äã¡£",
	"ÔÂ±ı½Úµ½ÁË£¡Ğê£¡±ğÖ¨Éù£¡¶Ô×ÅÆÁÄ»ÀÖÒ»ÏÂ£¡ÔÙÀÖÒ»ÏÂ£¡ºÇºÇ£¡ÎÒ¿´µ½ÁË£¡ºÃÁË£¡Ô¸Äã¿ìÀÖ£¡",
	"Ò»ÂÆÇéË¼Ò»¿Åºì¶¹£¬ÔÂÔ²Ê±·ÖÎÒ»áÈÃÓñÍÃËÍÈ¥ÎÒÌØÖÆµÄÔÂ±ı£¡ÖĞÇï¿ìÀÖ£¡",
	"¿´µ½ÄÇÂÖÃ÷ÔÂ£¬¾ÍÏëÆğÔ¶·½µÄÄã£»ãåÔ¡ÔÂ»ÔµÄÎÂÜ°£¬¾Í¸ĞÊÜµ½ÄãÎÂÈáµÄĞ¦Èİ¡£Ç×°®µÄ£¬ÎÒÏëÄã¡£ ",
	"ÖĞÇï¼Ñ½Ú£¬Ô¶Ô¶µÄÄã³ÔÔ²Ô²µÄ±ı¿´Ô²Ô²µÄÔÂÏëÔ²Ô²µÄÊÂ£¬²»ÒªÍüÁËÔ¶·½µÄÎÒ£¡ ",
	"Ìì²Ô²Ô£¬Ò°Ã£Ã££¬ÓĞ¸öÈË¶ùÔÚÔ¶·½¡£Çï·ç´µ£¬µ¾»¨Ïã¡£ÖĞÇï¿É·ñ»Ø¹ÊÏç£¿ ",
	"Ã÷ÔÂ±¾ÎŞ¼Û£¬¸ßÉ½½ÔÓĞÇé¡£Ô¸ÄãµÄÉú»î¾ÍÏñÕâÊ®ÎåµÄÔÂÁÁÒ»Ñù£¬Ô²Ô²ÂúÂú£¡ËÍÉÏÏãÌğµÄÔÂ±ı£¬Á¬Í¬Ò»¿Å×£¸£µÄĞÄ",
	"ÍøÔµ£¡ÇéÔµ£¡ÔÂÔ²£¡ÖĞÇïÖ®Ò¹¼ÄÏàË¼£¬»¨ºÃÔÂÔ²ÇéÄÑÔ²¡£´øÈ¥ÎÊºòºÍË¼Áµ£¬ĞÄÏëÊÂ³ÉÔ¸ÔµÔ²¡£",
	"ÏàË¼ÊÇÒ»ÖÖÅ¨Å¨µÄ¾Æ£¬×ÜÔÚ¾Ù±­Ê±É¢·¢³ö×íÈËµÄ·Ò·¼£»Ïç³îÊÇÒ»·İºñºñµÄÇé£¬×ÜÔÚÔÂÔ²Ê±Çá»½ÆğÄÑÑÔµÄã°âê¡£",
	"Ò»¸öÔÂÁÁÒ»¸öÄã£¬¶ş¸öÓ°×ÓÎÒºÍÄã£¬ÈıÉúÓĞĞÒÈÏÊ¶Äã£¬ËÄ¸öÔÂÀ´ºÃÏëÄã£¬ÎåºşËÄº£Ñ°ÕÒÄã£¬ÁùÉñÎŞÖ÷ÃÔÁµÄã£¬ÆßĞÇ°éÔÂÎ§ÈÆÄã£¬°ËÔÂÊ®ÎåÎÒµÈÄã¡£",
	"ÄãÊÇÔÂ±ıÎÒÊÇÏÚ£¬²ø²øÃàÃà×Ü¼ûÃæ£»ÄãÊÇ·çóİÎÒÊÇÏß£¬×·×·ÖğÖğ°ÑÄãÇ££»ÄãÊÇÃ÷ÔÂÎÒÊÇÈª£¬ÃÀÃÀÂúÂúÒ»ÍòÄê£¡",
	"Ã¿·ê¼Ñ½Ú±¶Ë¼Ç×£¬ÄãÎÒ¸ĞÇéËÆº£Éî£¬ÔÂÔ²ÓÖÊÇÔÂÃ÷Ê±£¬½ÌÎÒÔõÄÜ²»Ë¼¾ı£¡",
	"Á÷ĞÇ»®¹ıÌì¼Ê£¬ÎÒ´í¹ıÁËĞíÔ¸£»ÀË»¨ÅÄÉÏÑÒÊ¯£¬ÎÒ´í¹ıÁË×£¸££»¹ÊÊÂ½²ÁËÒ»±é£¬ÎÒ´í¹ıÁËñöÌı£»ÈËÉúÖ»ÓĞÒ»»Ø£¬ÎÒÇìĞÒÃ»ÓĞ´í¹ıÄãÕâ¸öºÃÓÑ£¡½ñÍíÑûÄã¹²Í¬ÉÍÔÂ£¡ ",
	"¾ÆÔ½¾ÃÔ½´¼£¬ÅóÓÑÏà½»Ô½¾ÃÔ½Õæ£»Ë®Ô½Á÷Ô½Çå£¬ÊÀ¼ä²×É£Ô½Á÷Ô½µ­¡£×£ÅóÓÑÖĞÇï¼Ñ½Ú¹ıµÃ¿ªĞÄ£¡ ",
	"È¥ÄêÔ²ÔÂÊ±£¬»¨µÆÁÁÈçÖç£»ÔÂÉÏÁøÉÒÍ·£¬ÈËÔ¼»Æ»èºó¡£½ñÄêÔ²ÔÂÊ±£¬ÔÂÓëµÆÒÀ¾É£»²»¼ûÈ¥ÄêÈË£¬ÀáÊª´ºÉÀĞä¡£",
	"ÖĞÇïÏàË¼£¬ÒâÅ¨Å¨£»ÀáÑÛÈË¶ù£¬ÃÎÔÚ»³£»ÔÂÊÇ¹ÊÏçÃ÷£¬ÈËÊÇÄã×îºÃ¡£",
	"Çå·çËÍÈ¥ÁËÎÒµÄ×£¸££¬Ã÷ÔÂ´øÀ´ÁËÎÒµÄÎÊºò£¬Á÷ĞÇ¼ÇÔØÁËÍùÈÕµÄ¹ÊÊÂ£¬ÓñÍÃÁôÏÂÁËÓÀºãµÄ¼ªÏé¡£×£ÄãÖĞÇï¼Ñ½Ú¿ìÀÖ£¬ÔÂÔ²ÈËÔ²ÊÂÊÂÔ²Âú£¡",
	"ÈË¸ôÇ§Àï¡¢Â·ÓÆÓÆ£¬È´´ıÒªÎÊ¡¢ÖÕÎŞÆ¾£¬ÇëÃ÷ÔÂ´ú´«Ñ¶£¬¼ÄÎÒÆ¬Ö½¶ùÎ¿ÀëÇé¡£",
	"Â¶´Ó½ñÒ¹°×£¬ÔÂÊÇ¹ÊÏçÃ÷¡£½ñÒ¹ÔÂÕıÔ²£¬ÕıÊÇË¼ÏçÊ±¡£Í¬Íûµ±¿ÕÔÂ£¬ÔÂÔ²ÃÎÎ´Ô²¡£",
	});
void get_chang();
void destruct_chang();
void generate_yutu();
void destroy_yutu();
void destroy_yuebing();
void generate_yuebing();
void yuetu_bonus(object player,object npc);
void update_record(object player);
void check_time2();
void paihangbang(object player,object npc);
void paihangbang_bonus(int vip,int potential,int cash,object player,object npc);
int check_yuebing(object who, int count,string name);
int give_yuebing(object who,string name, int count);
int exchange( object player,object npc);
int get_close();
// º¯Êı£ºÉú³É¶ş½øÖÆÂë
void SAVE_BINARY() { }
string get_save_file()	{ return "data/zhongqiu"SAVE_EXTENSION;}
void create()
{	
	restore();
	iStart = mktime(2007,9,24,8,0,0);	
   	iFinish = mktime(2007,9,26,22,0,0);
	iFinish_a = mktime(2007,10,3,22,0,0);
	call_out("check_time",1);
}

void check_time()
{
	int iTime;
	mixed* mixTime;

	iTime = get_party_time();
	remove_call_out("check_time");
	
	if(iTime < iStart)
	{
		call_out("check_time",iStart - iTime);
		return;
	}
	if ( iTime > iFinish_a )
	{
		destroy_yuebing();
		destroy_yutu();	
		destruct_chang();
		return;
	}
	if(iTime > iFinish)
	{
		destroy_yuebing();
		destroy_yutu();	
		get_chang();
		call_out("destruct_chang",iFinish_a - iTime);
		return;
	}
	mixTime = localtime(iTime);
	if(mixTime[TIME_HOUR] >= 22)
	{
		destroy_yuebing();//ÔÚ»î¶¯½áÊøÒÔºóÖ±½Ó½«ÓñÍÃºÍÔÂ±ı´Ó³¡¾°ÀïÃæÇå³ı¡£
		destroy_yutu();	
		call_out("check_time",3600*24 - mixTime[TIME_HOUR]*3600 - mixTime[TIME_MIN]*60);
		return;
	}

/*	delete_save_2("record");//×¥ÍÃÓ¢ĞÛ°ñµÄ¼ÇÂ¼ÔÚµÚ¶şÌì»î¶¯¿ªÊ¼Ç°¶¼ÊÇÓĞĞ§µÄ¡£ 
	delete_save_2("player");//Ã¿´Î»î¶¯¿ªÊ¼µÄÊ±ºò£¬¶¼½«ÉÏ´ÎµÄ¼ÇÂ¼¸øÇå³ıµô¡£
	save();
	YUTU->delete_2("player");//É¾³ıÍæ¼ÒÍÃ×ÓÊıÁ¿¼ÇÂ¼¡£*/

	if ( mixTime[TIME_HOUR] < 8 )
	{
		call_out("check_time",3600*8-mixTime[TIME_HOUR]*3600-mixTime[TIME_MIN]*60);
		return ;
	}
	check_time2();
}


void check_time2()
{
	int iTime;
	mixed *mixTime;
//	iTime = time();
	iTime = get_party_time();
	mixTime = localtime(iTime);
	get_chang();
	CHAT_D->sys_channel(0,"¸÷Î»Íæ¼ÒÖĞÇï¿ìÀÖ£¡×÷ÎªÖĞ»ªÃñ×å´«Í³½ÚÈÕµÄÖĞÇï½ÚÒÑ¾­À´ÁÙ£¬ÎªÁËÇì×£ÖĞÇïÍÅÔ²¼Ñ½Ú£¬´ó»°Õ½¹úÌØ±ğ¾Ù°ìÁËÎªÆÚÈıÌìµÄÖĞÇï»î¶¯À´Åã°é´ó¼Ò¡£´ó¼ÒÏÖÔÚ¸Ï¿ìÈ¥"HIR"ÖÜ¹ú"NOR"Ñ°ÕÒÖĞÇï»î¶¯Ô±¡ª¡ª"HIR"æÏ¶ğ"NOR"²ÎÓë»î¶¯°É£¬Ëı¾ÍÔÚÉñÏÉÒ¯Ò¯µÄÅÔ±ßÅ¶¡£");
	log_file( "zhongqiu_log.dat", sprintf( "%dÔÂ%dÈÕ %d £º%d µ±ÌìµÄÖĞÇï»î¶¯¿ªÊ¼¡£\n",mixTime[TIME_MON]+1,mixTime[TIME_MDAY],mixTime[TIME_HOUR],mixTime[TIME_MIN]) );
	if (mixTime[TIME_MIN]<30) 
	{
		kkkk=-1;
		generate_yutu();		
		log_file( "zhongqiu_log.dat", sprintf( "%dÔÂ%dÈÕ %d £º%d ·ÅÈëÓñÍÃ¡£\n",mixTime[TIME_MON]+1,mixTime[TIME_MDAY],mixTime[TIME_HOUR],mixTime[TIME_MIN]) );
		call_out("check_time3",60*(30-mixTime[TIME_MIN]));
	}
	else
	{
		kkkk=1;
		generate_yuebing();
//		CHAT_D->sys_channel(0,HIR"¾İËµÆß¹ú³ÇÍâµ½´¦¶¼ÊÇÔÂ±ı£¬²»ÖªµÀÊÇ²»ÊÇÕæµÄ£¬´ó¼Ò¸Ï¿ìÈ¥ÇÀ°¡£¡");
		CHAT_D->rumor_channel( 0, CHAT+HIR"¾İËµ°Ë¹ú³ÇÍâµ½´¦¶¼ÊÇÔÂ±ı£¬²»ÖªµÀÊÇ²»ÊÇÕæµÄ£¬´ó¼Ò¸Ï¿ìÈ¥ÇÀ°¡£¡" );  
		log_file( "zhongqiu_log.dat", sprintf( "%dÔÂ%dÈÕ %d £º%d ·ÅÈëÔÂ±ı¡£\n",mixTime[TIME_MON]+1,mixTime[TIME_MDAY],mixTime[TIME_HOUR],mixTime[TIME_MIN]) );
		call_out("check_time3",60*(60-mixTime[TIME_MIN]));
	}
}

void check_time3()
{
	int iTime,rate,level,z,p,x,y;
	int i,*nScene,size;
	mixed *mixTime;
	object robber;
	
	remove_call_out("check_time3");
//	iTime = time();
	iTime = get_party_time();	
	mixTime = localtime(iTime);
	if (get_close()) return;
	if ( iTime > iFinish_a )
	{
		destroy_yuebing();
		destroy_yutu();	
		destruct_chang();
		return;
	}
	if ( iTime > iFinish )
	{
		destroy_yuebing();
		destroy_yutu();	
		USER_D->user_channel("¸÷Î»Íæ¼Ò£¬ÖĞÇï½Ú»î¶¯¿ªÕ¹ÁËÈıÌì£¬ÔÚÕâ¶ÎÊ±¼äÀï£¬´ó¼ÒµÄÓ»Ô¾²ÎÓëÈÃÕû¸öÕ½¹úµÄÆø·Õ¿ÕÇ°ÈÈÁÒ£¬¸ĞĞ»´ó¼Ò¡£´Ë´Î»î¶¯µ½´ËÔ²Âú½áÊø£¬ÇëÅÅÃûÇ°Ê®µÄÍæ¼Ò¸Ï¿ìÖÁæÏ¶ğ´¦ÁìÈ¡ÅÅÃû½±Àø£¬ÁìÈ¡Ê±¼äÖÁ10ÔÂ3ÈÕ22£º00½ØÖ¹¡£");
		log_file( "zhongqiu_log.dat", sprintf( "%dÔÂ%dÈÕ %d £º%d ÖĞÇï»î¶¯È«²¿½áÊø¡£\n",mixTime[TIME_MON]+1,mixTime[TIME_MDAY],mixTime[TIME_HOUR],mixTime[TIME_MIN]) );
		call_out("destruct_chang",iFinish_a - iTime);
		return;
	}
	if(mixTime[TIME_HOUR] >= 22)
	{
		destroy_yuebing();//ÔÚ»î¶¯½áÊøÒÔºóÖ±½Ó½«ÓñÍÃºÍÔÂ±ı´Ó³¡¾°ÀïÃæÇå³ı¡£
		destroy_yutu();	
		USER_D->user_channel("½ñÌìµÄÖĞÇï»î¶¯µ½´Ë½áÊø£¬Ã÷ÌìµÄÍ¬Ò»Ê±¼ä´ó¼ÒÔÙÀ´²Î¼ÓÅ¶£¬×£´ó¼ÒÖĞÇïÓä¿ì¡£");
		call_out("check_time3",3600*24 - mixTime[TIME_HOUR]*3600 - mixTime[TIME_MIN]*60);
		log_file( "zhongqiu_log.dat", sprintf( "%dÔÂ%dÈÕ %d £º%d µ±ÌìµÄÖĞÇï»î¶¯½áÊø¡£\n",mixTime[TIME_MON]+1,mixTime[TIME_MDAY],mixTime[TIME_HOUR],mixTime[TIME_MIN]) );
		return;
	}

	if ( mixTime[TIME_HOUR] < 8 )
	{
		call_out("check_time3",3600*8-mixTime[TIME_HOUR]*3600-mixTime[TIME_MIN]*60);
		return ;
	}
	if ( mixTime[TIME_HOUR] == 8 && mixTime[TIME_MIN] < 30 )
		CHAT_D->sys_channel(0,"¸÷Î»Íæ¼ÒÖĞÇï¿ìÀÖ£¡×÷ÎªÖĞ»ªÃñ×å´«Í³½ÚÈÕµÄÖĞÇï½ÚÒÑ¾­À´ÁÙ£¬ÎªÁËÇì×£ÖĞÇïÍÅÔ²¼Ñ½Ú£¬´ó»°Õ½¹úÌØ±ğ¾Ù°ìÁËÎªÆÚÈıÌìµÄÖĞÇï»î¶¯À´Åã°é´ó¼Ò¡£´ó¼ÒÏÖÔÚ¸Ï¿ìÈ¥"HIR"ÖÜ¹ú"NOR"Ñ°ÕÒÖĞÇï»î¶¯Ô±¡ª¡ª"HIR"æÏ¶ğ"NOR"²ÎÓë»î¶¯°É£¬Ëı¾ÍÔÚÉñÏÉÒ¯Ò¯µÄÅÔ±ßÅ¶¡£");
	else
		CHAT_D->sys_channel(0,"´ó»°Õ½¹úÖĞÇï»î¶¯ÕıÔÚÈÈÁÒ½øĞĞÖĞ£¬Ïë²ÎÓëµÄ»°¾ÍÈ¥ÕÒÖĞÇï»î¶¯Ô±¡ª¡ª"HIR"æÏ¶ğ"NOR"°É£¬Ëı¾ÍÔÚ"HIR"ÖÜ¹ú"NOR"µÈ×ÅÄãÅ¶¡£");
	if ( kkkk == 1 )
	{
		generate_yutu();
		log_file( "zhongqiu_log.dat", sprintf( "%dÔÂ%dÈÕ %d £º%d ·ÅÈëÓñÍÃ¡£\n",mixTime[TIME_MON]+1,mixTime[TIME_MDAY],mixTime[TIME_HOUR],mixTime[TIME_MIN]) );
	}
	if ( kkkk == -1 )
	{
		generate_yuebing();
		CHAT_D->rumor_channel( 0, CHAT+HIR"¾İËµ°Ë¹ú³ÇÍâµ½´¦¶¼ÊÇÔÂ±ı£¬²»ÖªµÀÊÇ²»ÊÇÕæµÄ£¬´ó¼Ò¸Ï¿ìÈ¥ÇÀ°¡£¡" );  
//		CHAT_D->sys_channel(0,HIR"¾İËµÆß¹ú³ÇÍâµ½´¦¶¼ÊÇÔÂ±ı£¬²»ÖªµÀÊÇ²»ÊÇÕæµÄ£¬´ó¼Ò¸Ï¿ìÈ¥ÇÀ°¡£¡");
		log_file( "zhongqiu_log.dat", sprintf( "%dÔÂ%dÈÕ %d £º%d ·ÅÈëÔÂ±ı¡£\n",mixTime[TIME_MON]+1,mixTime[TIME_MDAY],mixTime[TIME_HOUR],mixTime[TIME_MIN]) );
	}
	kkkk=-kkkk;
	call_out("check_time3",1800);
}

// ·ÅÈëæÏ¶ğ
void get_chang()
{
	if ( !objectp(change) )
	{
		change = new("npc/party/0008");
		change->add_to_scene(80,286,178,4);
	}
}

// ÒÆ³ıæÏ¶ğ
void destruct_chang()
{
	if ( objectp(change) )
	{
		change->remove_from_scene();
		destruct(change);
	}
}

void generate_yutu()
{
	int i,z,p,x,y;
	object *nObj,npc;
	destroy_yutu();
	nObj = ({});	
	for(z=10;z<=80;z+=10)
	{
		for(i=0;i<50;i++)
		{
			if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) )
				continue;
			x = ( p % 1000000 ) / 1000;  y = p % 1000;
			npc = new("npc/party/yutu");
			if ( !objectp(npc) )
				continue;
			npc->add_to_scene(z,x,y);	
			nObj += ({ npc });	
		}
	}
	YUTU->set("npc",nObj);
}

void destroy_yutu()
{
	int i,size;
	object *nObj;
	nObj = 	YUTU->get("npc");
	for(i=0,size=sizeof(nObj);i<size;i++)
	{
		if ( !objectp(nObj[i])	)
			continue;
		nObj[i]->remove_from_scene();
		destruct(nObj[i]);
	}
	YUTU->delete("npc");
}
void generate_yuebing()
{
	int i,z,p,x,y;
	object *nObj,item;	
	destroy_yuebing();
	nObj = ({});
	for(z=10;z<=80;z+=10)
	{
		for(i=0;i<100;i++)
		{
			if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) )
				continue;
			x = ( p % 1000000 ) / 1000;  y = p % 1000;
			item = new(YUEBING);
			if ( !objectp(item) )
				continue;
			item->add_to_scene(z,x,y);	
			nObj += ({ item });
		}
	}
	YUTU->set("item",nObj);
}

void destroy_yuebing()
{
	int i,size;
	object *nObj;	
	nObj = YUTU->get("item");
	for(i=0,size=sizeof(nObj);i<size;i++)
	{
		if ( !objectp(nObj[i]) )
			continue;
		if ( get_d(nObj[i]) )
			continue;
		nObj[i]->remove_from_scene();
		destruct(nObj[i]);
	}
	YUTU->delete("item");
}
//ÉèÖÃÖĞÇï½Ú»î¶¯µÄ¿ªÆô
int set_open(object who,string arg)
{
	int year,mon,day,hour,min;
	string cTmp1,cTmp2;
	if ( sscanf(arg ,"%s-%s",cTmp1,cTmp2) != 2 )
	{
		send_user(who,"%c%s",'!',"´íÎóµÄ¸ñÊ½£¡");	
		return 0;
	}
	year = to_int(cTmp1[0..3]);
	mon = to_int(cTmp1[4..5]);
	day = to_int(cTmp1[6..7]);
	hour = to_int(cTmp1[8..9]);
	min = to_int(cTmp1[10..11]);
	iStart = mktime(year,mon,day,hour,min,0);	//»î¶¯¿ªÊ¼Ê±¼ä

	year = to_int(cTmp2[0..3]);
	mon = to_int(cTmp2[4..5]);
	day = to_int(cTmp2[6..7]);
	hour = to_int(cTmp2[8..9]);
	min = to_int(cTmp2[10..11]);
	iFinish = mktime(year,mon,day,hour,min,0);	//½áÊøÊ±¼ä

	if ( !iStart || !iFinish )
	{
		send_user(who,"%c%s",'!',"´íÎóµÄÊ±¼ä£¡");	
		return 0;
	}
	if ( iStart > iFinish || iFinish < time() )
	{
		send_user(who,"%c%s",'!',"´íÎóµÄÊ±¼ä£¡£¡");	
		return 0;
	}
	tell_user(who,"ÖĞÇï½Ú»î¶¯¿ªÆô£º%s£¡",arg);	
	send_user(who,"%c%s",'!',"ÖĞÇï½Ú»î¶¯¿ªÆô£¡");	
	save();
	call_out("check_time",3);
	return 1;
}
//ÉèÖÃÖĞÇï½Ú»î¶¯µÄ¹Ø±Õ
/*int set_close(object who)
{
	remove_call_out("check_time");
	iStart = 0;	
	iFinish = 0;		
	send_user(who,"%c%s",'!',"ÖĞÇï½Ú»î¶¯¹Ø±Õ£¡");	
	save();
	return 1;	
}*/
//»ñÈ¡ÖĞÇï½Ú»î¶¯×´Ì¬¡£
/*int is_open()
{
	mixed* mixTime;
	int iHour,iDay,iTime;
	mixTime = localtime(get_party_time());
	iHour = mixTime[TIME_HOUR];
   	iDay = mixTime[TIME_MDAY];
   	iTime = get_party_time();
	if(!iStart || !iFinish)//ÉèÖÃ»î¶¯¿ªÊ¼ºÍ½áÊøÊ±¼äÎŞĞ§¡£
	{
		return 0;
	}
	if(iTime < iStart || iTime > iFinish)//»¹Ã»ÓĞµ½Ê±¼äÒÔ¼°ÒÑ¾­»î¶¯¹ıÆÚ¡£
	{
		return 0;
	}
	if(iDay == 24 || iDay == 25 || iDay == 26)//9ÔÂ24 25 26 20:00-21:00
	{
		if(iHour == 20)
		{
			return 1;
		}
	}
	return 0;	
}*/
void do_look(object npc,object player)
{
	int index;
	string dailogue = "";
	string* choices1 = ({"½»»¹ÔÂÍÃ","×¥ÍÃÓ¢ĞÛ°ñ","ÔÂ±ı¶Ò»»","Ñ¯ÎÊÖĞÇï»î¶¯¹æÔò","Ñ¯ÎÊ»î¶¯Ê±¼ä",});
	string* choices2 = ({"ÔÂ±ı¶Ò»»","½»»¹ÔÂÍÃ","×¥ÍÃÓ¢ĞÛ°ñ","ÁìÈ¡Ó¢ĞÛ°ñµÄ½±Àø",});
	int iTime;
	mixed *mixTime;
	iTime = get_party_time();
	mixTime = localtime(iTime);
	if( iTime < iFinish )
//	if(is_open())
	{
		dailogue += "    ÖĞÇï¿ìÀÖ£¡½ñÌìÊÇÖĞÇï¼Ñ½Ú£¬ÎÒ´ø×ÅÓñÍÃ´ÓÔÂ¹¬×¨ÃÅÀ´µ½Õ½¹úÀï¸ø´ó¼ÒÇì×£½ÚÈÕ£¬µ«ÊÇÎÒ¸Õµ½´ËµØ£¬È´·¢ÏÖÓñÍÃ²»¼ûÁË£¡°¥£¬¿ÉÄÜËüÓÖ²»Ìı»°£¬×°°ç³ÉÔÂÍÃÔÚÕ½¹úÀïåĞÒ£¿ì»î°É¡£ÄãÄÜ°ïÎÒ°ÑËü×¥»ØÀ´Âğ£¿\n";
		for(index = 0; index < 5;index++)
		{
			dailogue+=sprintf(ESC"%s\ntalk %x# welcome.%d\n",choices1[index],getoid(npc),index+2);
		}
		send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"£º\n"+dailogue+ESC"Àë¿ª\n");
	}	
	else
	{
		dailogue += "    ÄãĞèÒªÎÒ°ïÃ¦Âğ£¿\n";
		for(index = 0; index < 4; index++)
		{
			dailogue+=sprintf(ESC"%s\ntalk %x# welcome.%d\n",choices2[index],getoid(npc),index+7);
		}
		send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"£º\n"+dailogue+ESC"Àë¿ª\n");	
	}	
}
void do_welcome( object npc, string arg )
{
	int flag,i,size,index,move,pos,record,index2,name_size;
	int id = getoid(npc);
       	object who,item,player,obj;  
       	string name,cTmp,id1,tmp="",cmd="",playername; 
        player = this_player();
        if ( sscanf(arg,"%d.%s",flag,id1) != 2 )//ÕâÀïÖ÷Òª´¦ÀíÊäÈëID×£¸£µÄĞÅÏ¢¡£
	{
        	flag = to_int(arg);
        }
        if(!flag)
        {
        	return;
        }
//        player->set_2("rabbit.day",localtime(get_party_time())[TIME_MDAY]);//¼ÇÂ¼ÓëæÏ¶ğ½»»¥µÄÊ±¼ä¡£	
        switch(flag)
        {
        case 1://ÀÖÒâ°ïÃ¦£¬ÎÒÏëÖªµÀÔÂÍÃÔÚÄÄÀï
		send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"£º\n"+"    ÔÚÖÜ¹ú¡¢Æë¹ú¡¢º«¹ú¡¢ÕÔ¹ú¡¢Îº¹ú¡¢ÇØ¹ú¡¢³ş¹úºÍÑà¹ú°Ë¸ö¹ú¼ÒµÄ¸½½ü£¬½«»á³öÏÖÔÂÍÃ£¬½«ËüÃÇÓÃÇ¬À¤Éş×¥×¡Ö®ºó»ØÀ´½»¸øÎÒ£¬¼´¿É»ñµÃ½±Àø¡£ÎÒ»¹»áÀÛ¼ÆÄãµÄ×¥ÍÃÊıÁ¿£¬²¢ÇÒ½«Õâ¸öÊıÁ¿ÅÅÃû£¬Èç¹ûÄãµÄÃû×ÖÄÜ³öÏÖÔÚ×¥ÍÃÓ¢ĞÛ°ñÉÏ£¬ÄÇÃ´ÎÒ½«¸øÓèÄãÒ»·İÖĞÇï´óÀñÅ¶£¬ºÇºÇ¡£\n"+ESC"È·¶¨\n");
        	break;
        case 2://½»»¹ÔÂÍÃ£¬ÅÅĞĞ
		if( get_party_time() > iFinish ) return ;
		if ( check_yuebing(player,1,"Ğ¡ÔÂÍÃ") != 1 )
		{
			send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"£º\n"+"    ºÜ±§Ç¸£¬ÄãºÃÏñÃ»ÓĞ²¶×½µ½ÔÂÍÃ¡£\n"+ESC"È·¶¨\n");
			return ;
		}
		player->add_save("tuzi",1);
		yuetu_bonus(player,npc);//¸øÓñÍÃ½±Àø¡£
		update_record(player);//ÕâÀï¸üĞÂÍÃ×ÓÊıÁ¿¼ÇÂ¼ÒÔ¼°ÅÅĞĞ°ñ¡£
		break;
        case 3://×¥ÍÃÓ¢ĞÛ°ñ,
		paihangbang(player,npc);
        	break;
        case 4://ÔÂ±ı¶Ò»»(Ç°)
        	send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf("%s£º\n    ÖĞÇï¼Ñ½Ú±¶Ë¼Ç×¡£ÔÚÕâ¸öÌØ±ğµÄ½ÚÈÕÀï£¬ÄãÊÇ·ñÒ²ÓĞË¼ÄîµÄÈË£¿ÄãÊÇ·ñÓĞºÜ¶à»°Ïë¶ÔÄãË¼ÄîµÄÈËËµ£¿ÄÇ¸Ï½ôÈ¥ËÑ¼¯ÔÂ±ı°É£¡ÄÇ¸Ï½ôÈ¥ËÑ¼¯ÔÂ±ı°É£¡ÎÒ»á°ïÖúÄãÊµÏÖÔ¸ÍûµÄÅ¶£¡£¡\n"ESC"½»³ö1¸öÔÂ±ı¶Ò»»ÉñÃØÀñÎï\ntalk %x# welcome.13\n"ESC"½»³ö5¸öÔÂ±ıÏòÅóÓÑ·¢³öÎÂÜ°µÄ×£¸£\ntalk %x# welcome.14\n"ESC"Àë¿ª",npc->get_name(),id,id));  	
        	break;
        case 7://ÔÂ±ı¶Ò»»(ºó)
        	send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf("%s£º\n    ÖĞÇï»î¶¯Ê±¼äÒÑ¾­¹ıÁË£¬²»¹ıÎÒ»¹ÊÇ»á°ïÄã¶Ò»»½±ÀøµÄ£¡\n"ESC"½»³ö1¸öÔÂ±ı¶Ò»»ÉñÃØÀñÎï\ntalk %x# welcome.13\n"ESC"Àë¿ª",npc->get_name(),id,id));  	
        	break;
        case 5://Ñ¯ÎÊÖĞÇï»î¶¯¹æÔò
        	send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf("%s£º\n    ÔÚ»î¶¯ÆÚ¼ä£¬ÖÜ¹ú¡¢Æë¹ú¡¢º«¹ú¡¢ÕÔ¹ú¡¢Îº¹ú¡¢ÇØ¹ú¡¢³ş¹úºÍÑà¹ú°Ë¸ö¹ú¼ÒµÄ¸½½ü£¬½«»á³öÏÖÔÂÍÃ£¬ÓÃ"HIR"Ç¬À¤Éş"NOR"½«ËüÃÇ×¥×¡Ö®ºó»ØÀ´½»¸øÎÒ£¬¼´¿É»ñµÃ½±ÀøÅ¶£¬ÎÒ»¹»á¼ÇÂ¼ÏÂÄã×¥ÍÃµÄÊıÁ¿£¬Èç¹ûÄãÄÜÔÚ"HIR"×¥ÍÃÓ¢ĞÛ°ñ"NOR"ÉÏ»ñµÃÃû´Î£¬ÄÇ½«»á»ñµÃÖĞÇïÌØ±ğÀñÎïÒ»·İ£¬ÆäÖĞ°üº¬ÁË¼«ÖÁÉñÃØµÄĞÂ·¨±¦¡ª¡ª´ãÔÂÖ®»·£¡ÃûÁĞÇ°ÈıµÄÍæ¼Ò¸ü»á»ñµÃ¹Ù·½½±ÀøVIP°üÒ»¸öÓ´¡£ÏëÒª»ñµÃµÄ»°£¬¾ÍÒªÅ¬Á¦×¥ÍÃÅ¶£¡\n    ÁíÍâÔÚ°Ë¸ö¹ú¼Ò³ÇÍâ»¹»áË¢³öÔÂ±ı£¬Ö»ÒªÄÃ×ÅÕâĞ©ÔÂ±ıÒ²¿ÉÒÔÔÚÎÒÕâÀï¶Ò»»Ò»¶¨µÄ½±ÀøÅ¶£¡\n"ESC"È·¶¨\n",npc->get_name()));  	
        	break;	 
        case 6://Ñ¯ÎÊ»î¶¯Ê±¼ä
        	send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf("%s£º\n    »î¶¯Ê±¼äÊÇ9ÔÂ24ÈÕµ½9ÔÂ26ÈÕ£¬Ã¿ÌìµÄ08£º00µãµ½22£º00µã£¡\n"ESC"È·¶¨",npc->get_name()));
		break;
	case 8:
		send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"£º\n"+"    »î¶¯Ê±¼äÒÑ¾­¹ıÁË£¬½»»¹ÔÂÍÃÖ»ÄÜ»ñµÃ½±Àø£¬²»»á¼ÆÈë×¥ÍÃÓ¢ĞÛ°ñÅ¶£¡ÄãÈ·¶¨Òª½»»¹ÔÂÍÃÂğ£¿\n"+sprintf(ESC"È·¶¨\ntalk %x# welcome.12\n",getoid(npc))+ESC"Àë¿ª\n");
		break;
        case 12://½»»¹ÔÂÍÃ£¬²»ÅÅĞĞ
		if ( check_yuebing(player,1,"Ğ¡ÔÂÍÃ") != 1 )
		{
			send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"£º\n"+"    ºÜ±§Ç¸£¬ÄãºÃÏñÃ»ÓĞ²¶×½µ½ÔÂÍÃ¡£\n"+ESC"È·¶¨\n");
			return ;
		}
		yuetu_bonus(player,npc);//¸øÓñÍÃ½±Àø¡£
		break;
        case 13://½»³ö1¸öÔÂ±ı¶Ò»»½ÚÈÕÀñÎï
        	if(check_yuebing(player,1,"ÔÂ±ı") == 0   )
		{
			send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf("%s£º\n    ºÜ±§Ç¸Å¶£¬ÄãµÄÔÂ±ıºÃÏóÊıÁ¿²»×ã£¬¸Ï½ôÔÙÈ¥ÊÕ¼¯°É£¬ºÇºÇ£¡\n"ESC"È·¶¨",npc->get_name()));
			return ;	
		}
        	//¸øÓèÔÂ±ı¶Ò»»µÄ½±Àø¡£
        	exchange(player,npc);
        	break;
        case 14://½»»¹5¸öÔÂ±ıÒÔÏòÅóÓÑ·¢³öÎÂÜ°µÄ×£¸£
        	if ( check_yuebing(player,5,"ÔÂ±ı") == 0 )
        	{
			send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf("%s£º\n    ºÜ±§Ç¸Å¶£¬ÄãµÄÔÂ±ıºÃÏóÊıÁ¿²»×ã£¬¸Ï½ôÔÙÈ¥ÊÕ¼¯°É£¬ºÇºÇ£¡\n"ESC"È·¶¨",npc->get_name()));
			return ;        			
        	}
		send_user( player, "%c%c%d%s", '?', 16, 30, "ÇëÄúÊäÈëÄúºÃÓÑµÄID£¬ÎÒ¾ÍÄÜÏòÄúµÄÅóÓÑ·¢³ö×£¸£¡£Èç¹ûÄúÊäÈë0µÄ»°£¬¾Í¿ÉÒÔÏòËùÓĞÍæ¼Ò·¢³ö×£¸££º\n"+sprintf( ESC"talk %x# welcome.15",getoid(npc))+".%s\n");
        	break;
        case 15://´¦ÀíÎÂÜ°µÄ×£¸£¡£
        	if ( !sizeof(id1) )
        		return ;
        	cTmp = nWord[random(sizeof(nWord))];
        	if ( id1 == "0" )
        		name = "´ó¼Ò";
		else
		{        
			i = to_int(id1);
			if ( !i )
				return ;	
        		obj = find_char(id1);
       			if ( !objectp(obj) )
			{
        			if( !( player->get_friend_id(i) ) )//Íæ¼Ò²»ÔÚÏß²¢ÇÒ²»ÔÚºÃÓÑÁĞ±í£¬²»·¢ËÍ×£¸£.
        			{
//					name = "´ó¼Ò";
					send_user(player,"%c%s",'!',"¶Ô²»Æğ£¬¸ÃÍæ¼Ò²»´æÔÚ");
					return ;
				}
				else
				{
					name = player->get_friend_name(i);
//					MAILBOX->send_mail(player,i,cTmp);
//					MAILBOX->sys_mail(obj->get_id(),obj->get_number(),cTmp);
				}				
			}
			else
				name = obj->get_name();
			if(name == player->get_name())
			{
				send_user(player,"%c%s",'!',"Äã²»ÄÜ¸ú×Ô¼º·¢ËÍ×£¸££¡");
				return;
			}						
		}
		if ( give_yuebing(player,"ÔÂ±ı",5) == 0 )
        	{
			send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf("%s£º\n    ºÜ±§Ç¸Å¶£¬ÄãµÄÔÂ±ıºÃÏóÊıÁ¿²»×ã£¬¸Ï½ôÔÙÈ¥ÊÕ¼¯°É£¬ºÇºÇ£¡\n"ESC"È·¶¨",npc->get_name()));
			return ;        			
        	}
        	cTmp = sprintf(HIY"%s"HIR"¶Ô"HIY"%s"HIR"Ëµ£º%s",player->get_name(),name,cTmp); 		
		if (objectp(obj)) MAILBOX->sys_mail(obj->get_id(),obj->get_number(),cTmp);
        	CHAT_D->sys_channel(0,HIR+cTmp);
		send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
        	break;
	case 9://×¥ÍÃÓ¢ĞÛ°ñ,
		paihangbang(player,npc);
		break;
	case 10://ÁìÈ¡ÅÅĞĞ°ñµÄ½±Àø
		if(get_save_2(sprintf("player.%d.bonus",player->get_number())))
		{
			send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"£º\n"+"    ÄãÒÑ¾­ÁìÈ¡¹ı¸Ã½±Àø£¬²»ÄÜÖØ¸´ÁìÈ¡Å¶£¡\n"+ESC"È·¶¨\n");
			return;
		}
		pos = get_save_2(sprintf("player.%d.pos",player->get_number()));//ÔÚÅÅĞĞ°ñµÄÎ»ÖÃ¡£				
		if ( pos<1 || pos > 10 )
		{
			send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"£º\n"+"    ±§Ç¸£¬ÄãµÄÃû×Ö²¢²»ÔÚ×¥ÍÃÅÅĞĞ°ñÉÏÅ¶£¡\n"+ESC"È·¶¨\n");
			return ;	
		}
//		if(player->get_2("rabbit.day")== localtime(get_party_time())[TIME_MDAY])
		{
			send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf("%s£º\n    ºÇºÇ£¬ÄãºÜÀ÷º¦ÄØ£¬ÕâÊÇ¸øÓèÄãµÄ½±ÀøÅ¶£¬ÇëÊÕÏÂ°É£¡\n"+sprintf(ESC"ÁìÈ¡½±Àø¡£\ntalk %x# welcome.16\n",getoid(npc)),npc->get_name()));
		}
		break;
	case 16:
		if(get_save_2(sprintf("player.%d.bonus",player->get_number())))
		{
			send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"£º\n"+"    ÄãÒÑ¾­ÁìÈ¡¹ı¸Ã½±Àø£¬²»ÄÜÖØ¸´ÁìÈ¡Å¶¡£\n"+ESC"È·¶¨\n");
			return;
		}	
		pos = get_save_2(sprintf("player.%d.pos",player->get_number()));//ÔÚÅÅĞĞ°ñµÄÎ»ÖÃ¡£
		if ( pos<1 || pos > 10 )
		{
			send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"£º\n"+"    ±§Ç¸£¬ÄãµÄÃû×Ö²¢²»ÔÚ×¥ÍÃÅÅĞĞ°ñÉÏÅ¶£¡\n"+ESC"È·¶¨\n");
			return ;	
		}
		switch(pos)
		{
		case 1:
			paihangbang_bonus(1,1000,100000,player,npc);
			break;
		case 2:
			paihangbang_bonus(1,900,90000,player,npc);
			break;
		case 3:
			paihangbang_bonus(1,800,80000,player,npc);
			break;
		case 4:
			paihangbang_bonus(0,700,70000,player,npc);
			break;
		case 5:
			paihangbang_bonus(0,600,60000,player,npc);
			break;
		case 6:
			paihangbang_bonus(0,500,50000,player,npc);
			break;
		case 7:
			paihangbang_bonus(0,400,40000,player,npc);
			break;
		case 8:
			paihangbang_bonus(0,300,30000,player,npc);
			break;
		case 9:
			paihangbang_bonus(0,200,20000,player,npc);
			break;	
		default:
			paihangbang_bonus(0,100,10000,player,npc);	
		}
		break;
        }      
}
//ÎïÆ·½±Àø
void move_to_user(object player, int amount_s, string name,object npc)
{
	int p,total,amount;
	object item;
	string name_s;
	item = new(name);
	if (item)
	{
		name_s=item->get_name();
		if( item->get_max_combined()>1 )
		{
			total = amount_s;
			amount = USER_INVENTORY_D->carry_combined_item(player, item, total);
		        if( amount > 0 && item->set_amount(amount) )
		        {
		                if( p = item->move(player, -1) )
		                {
		                        item->add_to_user(p);
		                }
		        }
		        else
		        {
		        	item->add_amount( -total );
		        }
		}
		else
		{
			if( p = item->move(player, -1) )
		        {
		                item->add_to_user(p);
		        }
		}
		USER_D->user_channel("¹§Ï²"+player->get_name()+"ÔÚÖĞÇï½Ú»î¶¯ÖĞ»ñµÃ"+HIR+name_s+"¡£\n");
	}
}
//¸øÓèÅÅĞĞ°ñµÄ½±Àø
void paihangbang_bonus(int vip,int potential,int cash,object player,object npc)
{
	int flag = 0,iVipTime,iVip;
	int id = player->get_number();
	mixed* mixTime;

	if(sizeof_inventory(player, 1, MAX_CARRY) >= MAX_CARRY )
	{
		send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"£º\n	ºÜ±§Ç¸£¬ÏëÒª»ñµÃ½±Àø£¬ÇëÇåÀíÄãµÄµÀ¾ßÀ¸¿Õ¼ä¡£Èç¹û¾­ÑéºÍÇ±ÄÜ´ïµ½ÉÏÏŞ£¬Ò²ÊÇ²»ÄÜÁìÈ¡½±ÀøµÄÓ´¡£"+ESC"È·¶¨\n");
		return;
	}
	move_to_user(player,1,YUEHUAN,npc);
	if(vip)//¸ø³öVIPĞ§¹ûµ½Íæ¼ÒÉíÉÏ¡£
	{
		iVip = player->get_vip();
		if ( iVip != 0 && iVip != 1 )
			return 0;
		iVipTime = player->get_save_2("vip_package.time");
		if ( iVipTime == 0 )
			iVipTime = time()+3600*24*31;
		else 
			iVipTime += 3600*24*31;
		if ( iVip == 0 )
			player->delete_save_2("vip_package");
		player->delete_save_2("vip_package.trial");	//ÊÔÓÃVIP°ü
		player->set_vip(1);
		player->add_save_2("vip_package.doubles",40);
		player->set_save_2("vip_package.time",iVipTime);
		player->add_title("V001");
		send_user( player, "%c%w%w%c", 0x81, 7401, 999, EFFECT_GOOD );
		USER_ENERGY_D->count_cp(player);
		USER_ENERGY_D->count_pp(player);
		USER_ENERGY_D->count_ap(player);
		USER_ENERGY_D->count_dp(player);
		mixTime = localtime(iVipTime);
		send_user(player,"%c%s",';',sprintf("Äã°ó¶¨ÁËVIP°ü£¬VIP°ó¶¨µÄµ½ÆÚÊ±¼äÊÇ%d-%02d-%02d %02d:%02d:%02d¡£¹Û²ìVIPĞ§¹ûÃèÊö¼´¿ÉÁË½âµ½ÆÚÊ±¼ä¡£ÄãÒ²¿ÉÒÔÈ¥ÕÒÉñÏÉÒ¯Ò¯²éÑ¯VIP°ó¶¨µ½ÆÚµÄÊ±¼ä¡£",mixTime[TIME_YEAR],mixTime[TIME_MON]+1,mixTime[TIME_MDAY],mixTime[TIME_HOUR],mixTime[TIME_MIN],mixTime[TIME_SEC]));
		send_user( player, "%c%w%s", 0x82, 7401, "item/sell/0061"->get_loop_desc(player));
		send_user( player, "%c%c%c", 0xA2, 4, 1);
		send_user( player, "%c%c%c", 0xA2, 3, 3-player->get_save_2("vip_package.revive.count"));
		"item/sell/0061"->send_vip_to_friend(player,1);
		USER_D->user_channel("¹§Ï²"+player->get_name()+"ÔÚÖĞÇï½Ú»î¶¯ÖĞ»ñµÃ"+HIR+"VIP°ü"+"¡£\n");
	}
	player->add_potential(potential);//Ç±ÄÜ
	player->add_cash(cash);//½ğÇ®	
	set_save_2(sprintf("player.%d.bonus",id),1);
	save();
}
void paihangbang(object player,object npc)
{
	int index,pos,name_size,id;  
       	string tmp="",cmd="",playername,blank="";
       	blank = repeat_string(" ",12); 

	for(index = 1; index<=5;index++)
	{
		id = get_save_2(sprintf("record.%d",index));//ÕÒµ½indexÎ»ÖÃËù¶ÔÓ¦µÄid.
		if(!id)
		{
			tmp = sprintf(" ""%2d£®%12s%4s%4s",index,blank,"£º\t","¿ÕÈ±");
			tmp+="\t\t";
			tmp += sprintf(" ""%2d£®%12s%4s%4s",index+5,blank,"£º\t","¿ÕÈ±");
			tmp+="\n";
		}
		else
		{
			playername = get_save_2(sprintf("player.%d.name",id));
			name_size = strlen(playername);
			if(name_size<=12)
			{
				playername+= repeat_string(" ",12-name_size);
			}
			switch(index)
			{
			case 1:
				tmp = sprintf(" ""R""%2d£®%12s%4s%4d"NOR,1,playername,"£º\t",get_save_2(sprintf("player.%d.count",id)));
					//tmp+="      ";
				break;
			case 2:
				tmp = sprintf(" ""M""%2d£®%12s%4s%4d"NOR,2,playername,"£º\t",get_save_2(sprintf("player.%d.count",id)));
					//tmp+="  ";
				break;
			case 3:
				tmp = sprintf(" ""B""%2d£®%12s%4s%4d"NOR,3,playername,"£º\t",get_save_2(sprintf("player.%d.count",id)));
					//tmp+="   ";
				break;
			case 4:
				tmp = sprintf(" ""%2d£®%12s%4s%4d",4,playername,"£º\t",get_save_2(sprintf("player.%d.count",id)));	//+BLK+BLK
					//tmp+="       ";
				break;		
			case 5:
				tmp = sprintf(" ""%2d£®%12s%4s%4d",5,playername,"£º\t",get_save_2(sprintf("player.%d.count",id)));	//+BLK+BLK
				break;							
			}	
			tmp+="\t\t";
			id = get_save_2(sprintf("record.%d",index+5));
			if(!id)
			{
				tmp += sprintf(" ""%2d£®%12s%4s%4s",index+5,blank,"£º\t","¿ÕÈ±");
			}
			else
			{
				playername = get_save_2(sprintf("player.%d.name",id));
				name_size = strlen(playername);
				if(name_size<=12)
				{
					playername+= repeat_string(" ",12-name_size);
				}
				tmp += sprintf(" ""%2d£®%8s%4s%4d",index+5,playername,"£º\t",get_save_2(sprintf("player.%d.count",id)));
//				tmp += sprintf(" ""%2d£®%8s%4s%4d",index+5,get_save_2(sprintf("player.%d.name",id)),"£º\t",get_save_2(sprintf("player.%d.count",id)));//+BLK+BLK
			}		
			tmp+="\n";
		}
		cmd+=tmp;
		
	}
//	log_file("zhongqiu.txt",short_time() + "\n"+cmd );
       	send_user( player, "%c%c%w%s", ':',3,npc->get_char_picid(), sprintf("×¥ÍÃÓ¢ĞÛ°ñ£¨ÄãÏÖÔÚÒÑ¾­½»ÁË%dÖ»ÔÂÍÃ£© \n",player->get_save("tuzi"))+cmd
		+ESC "È·¶¨\n");
}
int exchange( object player,object npc) 
{
	int rand,p,cash,exp,pot;
	if(sizeof_inventory(player, 1, MAX_CARRY) >= MAX_CARRY )
	{
		send_user(player,"%c%s",'!',"ÄãÉíÉÏµÄµÀ¾ßÀ¸¿Õ¼ä²»¹»£¬ÎŞ·¨ÁìÈ¡½±Àø£¬ºÜ±§Ç¸£¬ÏÂ´Î¶Ò»»½±ÀøÊ±¿ÉÒª×¢ÒâÅ¶¡£");
		return;
	}
	if ( give_yuebing(player,"ÔÂ±ı",1) == 0 )
        {
		send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf("%s£º\n    ºÜ±§Ç¸Å¶£¬ÄãµÄÔÂ±ıºÃÏóÊıÁ¿²»×ã£¬¸Ï½ôÔÙÈ¥ÊÕ¼¯°É£¬ºÇºÇ£¡\n"ESC"È·¶¨",npc->get_name()));
		return ;        			
        }
	rand = random(10000);
	if(rand < 2000)
	{
		move_to_user(player, 1, "item/91/9101",npc);//»îÂçÍè¡£
	}
	else if(rand < 4000)
	{
		move_to_user(player, 1, "item/91/9111",npc);//°²ÉñÍè¡£
	}
	else if(rand < 5500)
	{
		move_to_user(player, 1, "item/91/9102",npc);//Ôì»¯µ¤¡£	
	}
	else if(rand < 7000)
	{
		move_to_user(player, 1, "item/91/9112",npc);//²¹ĞÄµ¤¡£		
	}
	else if(rand < 8000)
	{
		move_to_user(player, 1, "item/91/9120",npc);//¾È¼±µ¤¡£	
	}
	else if(rand < 9000)
	{
		move_to_user(player, 1, "item/91/9121",npc);//»îĞÄµ¤¡£
	}
	else if(rand < 9450)
	{
		player->add_cash(20000);//20000½ğÇ®
		USER_D->user_channel("¹§Ï²"+player->get_name()+"ÔÚÖĞÇï½Ú»î¶¯ÖĞ»ñµÃ"+HIR"20000½ğÇ®"+"¡£\n");
	}
	else if(rand < 9850)
	{
		move_to_user(player,1,"item/44/4488",npc);//Ëæ»ú ³èÎï¼¼ÄÜµ¤
	}
	else if(rand < 9990)
	{
		move_to_user(player,1,"item/std/8000",npc);//²Ø±¦Í¼
	}
	else
	{
		move_to_user(player,1,YUEHUAN,npc);//ÔÂ»·
	}
	send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf("%s£º\n    ×£ÄãÖĞÇï¿ìÀÖ£¬½ÚÈÕÀñÎïÒÑ¾­ËÍ¸øÁËÄã£¬Çë¿ì¿ì²é¿´Ò»ÏÂ°É£¡\n",npc->get_name()));
}
//¼ì²éÍæ¼ÒµÀ¾ßÀ¸ÉÏÃæÊÇ·ñÓĞcount¸öname¡£ÊÇµÄ»°£¬¾Í·µ»Ø1£¬·ñÔò·µ»Ø0¡£
int check_yuebing(object who, int count,string name)
{
	int i,size,amount;
	object *inv,item;	
	inv = all_inventory(who, 1, MAX_CARRY*4);
	if(!inv)
	{
		return 0;
	}
	if( !(objectp( item = present(name, who, 1, MAX_CARRY*4) )) || (item->is_zhongqiu() != 1) )
	{		
		return 0;	
	}		
	for(i=0,size=sizeof(inv);i<size;i++)
	{
		if ( !objectp(inv[i]) )
			continue;
		if ( inv[i]->get_name() != name || inv[i]->is_zhongqiu() != 1 )
			continue;
		if ( inv[i]->is_combined() )//Èç¹û¿ÉÒÔµş¼ÓµÄ»°£¬ÄÇÃ´¾ÍÔö¼Óµş¼ÓµÄÊıÁ¿¡£
			amount += inv[i]->get_amount();		
		else
			amount ++;
	}
	if ( amount < count )
	{
		return 0;	
	}
	return 1;
}
//Èç¹ûÍæ¼ÒÉíÉÏÓĞ×ã¹»µÄcount¸öÊıÄ¿£¬ÄÇÃ´¾Í±éÀúµÀ¾ßÀ¸½øĞĞ¿Û³ı¡£
int give_yuebing(object who, string name,int count)
{
	int i,size,amount;
	object *inv,item;	
	if ( check_yuebing(who,count,name) != 1 )
		return 0;
	inv = all_inventory(who, 1, MAX_CARRY*4);
	for(i=0,size=sizeof(inv);i<size;i++)
	{
		if ( !objectp(inv[i]) )
			continue;
		if ( inv[i]->get_name() != name || inv[i]->is_zhongqiu() != 1 )//
			continue;
		amount = inv[i]->get_amount();
		if ( count >= amount )
		{
			count -= amount;//ÕâÀï×ö¸öĞŞÕı¡£Èç¹ûÍæ¼Ò¸øµÄÊıÁ¿³¬¹ıÊµ¼ÊµÀ¾ßÀ¸ÉÏ¶ÔÓ¦ÎïÆ·ÊıÁ¿µÄ»°¡£
			inv[i]->remove_from_user();//ÕâÀï½«Íæ¼ÒµÀ¾ßÀ¸ÉÏµÄ¶ÔÓ¦ÎïÆ·Çå¹â¡£
			destruct(inv[i]);			
		}
		else//·ñÔò¼õÈ¥ÏàÓ¦ÊıÄ¿¡£
		{
			inv[i]->add_amount(-count);
			count = 0;	
		}
		if ( count <= 0 )
			break;
	}
	return 1;		
	
}

//ÔÚ½»»¹ÔÂÍÃµÄÊ±ºò£¬¸üĞÂÔÂÍÃµÄÊıÁ¿¼ÇÂ¼ÅÅĞĞ°ñ¡£
void update_record(object player)
{
	/*
	Ê×ÏÈ»ñµÃÍæ¼ÒµÄidĞÅÏ¢£¬Èç¹ûÓĞµÄ»°£¬
	ÄÇÃ´¾ÍÕÒËûµÄid¶ÔÓ¦µÄÔÂÍÃÊıÁ¿¼ÇÂ¼£¬²¢ÇÒÀÛ¼Ó1
	Èç¹ûÅÅĞĞ°ñÃûµ¥¸öÊıĞ¡ÓÚ10µÄ»°£¬ÄÇÃ´¾Í½«Õâ¸öĞÂÀ´µÄÌí¼Óµ½ÅÅĞĞ°ñÉÏÃæ£¬
	Òª¼Ç×¡Õâ¸öÍæ¼ÒµÄid,Íæ¼ÒµÄposition,ÒÔ¼°Õâ¸öÅÅĞĞ°ñµÄ´óĞ¡¡£
	Èç¹ûÅÅĞĞ°ñÃûµ¥¸öÊı´óÓÚ10µÄ»°£¬ÄÇÃ´¾Í½øĞĞ±È½Ï£¬ÕÒ³öÅÅĞĞ°ñÉÏÃæÔÂÍÃÊıÁ¿±È×Ô¼ºÉÙµÄ£¬
	ÕâÑùµÄ»°£¬¾Í½«ÄÇ¸ö±È×Ô¼ºÉÙµÄÉ¾³ıµô£¬²¢ÇÒ½«×Ô¼º¼ÓÈëµ½ÅÅĞĞ°ñÉÏÃæ¡£
	×îºó½øĞĞÈ«²¿Êı¾İµÄÅÅĞò¡£
	*/
	int size,index,pos,oldid,id1,amount,i;
	int id = player->get_number();
	string name = player->get_name();
//	amount = YUTU->get_2(sprintf("player.%d.rabbit",id));//Ôö¼Ó¸ÃÍæ¼ÒµÄÅÅĞĞ°ñÍÃ×ÓÊıÁ¿¡£
	amount = player->get_save("tuzi");//»ñÈ¡¸ÃÍæ¼ÒµÄÅÅĞĞ°ñÍÃ×ÓÊıÁ¿¡£
	if(get_save_2(sprintf("player.%d",id)))
	{
		if(get_save_2(sprintf("player.%d.name",id))== name)//ÕÒµ½Ô­À´ÅÅĞĞ°ñÉÏÒÑ¾­ÓĞ¼ÇÂ¼µÄÍæ¼Ò£¬
		{
//			add_save_2(sprintf("player.%d.count",id),1);//²¢ÇÒ½«¼ÇÂ¼Ôö¼Ó1¡£
			set_save_2(sprintf("player.%d.count",id),amount);
			pos = get_save_2(sprintf("player.%d.pos",id));//»ñµÃ¶ÔÓ¦Íæ¼ÒÔÚÅÅĞĞ°ñÉÏµÄÎ»ÖÃ¡£
		}
	}
	else if((size = get_save_2(sprintf("record.size"))) < 10)//ÅĞ¶ÏÅÅĞĞ°ñµÄ´óĞ¡ÊÇ·ñÒÑ¾­³¬³ö10¡£
	{
			pos = size+1;
			set_save_2("record.size",pos);//¸üĞÂÅÅĞĞ°ñµÄ´óĞ¡¡£
			set_save_2(sprintf("record.%d",pos),id);//±£´æÅÅĞĞ°ñposÎ»ÖÃ¶ÔÓ¦µÄid¡£
			set_save_2(sprintf("player.%d.name",id),name);//±£´æidÍæ¼ÒµÄĞÕÃû
			set_save_2(sprintf("player.%d.pos",id),pos);
			set_save_2(sprintf("player.%d.count",id),amount);//±£´æÍæ¼Ò½»»¹ÔÂÍÃµÄÊıÄ¿¡£
	}
	else 
	{
		oldid = get_save_2(sprintf("record.%d",size));
		if(get_save_2(sprintf("player.%d.count",oldid))< amount)
		{
			pos = size;
			delete_save_2(sprintf("player.%d",oldid));//É¾³ıÕâ¸ö¾É¼ÇÂ¼
			set_save_2(sprintf("record.%d",pos),id);//±£´æÅÅĞĞ°ñÍæ¼Òµ±Ç°ÅÅĞĞÉÏµÄid¡£
			set_save_2(sprintf("player.%d.name",id),name);//±£´æÍæ¼ÒµÄĞÕÃû
			set_save_2(sprintf("player.%d.pos",id),pos);//¼ÇÂ¼Ãû´Î
			set_save_2(sprintf("player.%d.count",id),amount);//±£´æÍæ¼Ò½»»¹ÔÂÍÃµÄÊıÄ¿¡£
			set_save_2("record.size",pos);//±£´æÅÅĞĞ°ñµÄ´óĞ¡¡£		
		}
	}
	if(pos)
	{
		for(index = pos; index > 1; index--)
		{
			id = get_save_2(sprintf("record.%d",index));
			id1 = get_save_2(sprintf("record.%d",index-1));
			if(get_save_2(sprintf("player.%d.count",id1))>= get_save_2(sprintf("player.%d.count",id)))
			{
				break;
			}
			set_save_2(sprintf("record.%d",index),id1);			
			set_save_2(sprintf("player.%d.pos",id1),index);
			set_save_2(sprintf("record.%d",index-1),id);
			set_save_2(sprintf("player.%d.pos",id),index-1);	
		}
		save();
	}
	
}

//½»»¹ÔÂÍÃ£¬»ñµÃ½±Àø
void yuetu_bonus(object player,object npc)
{
	int rand,id,move,level;
	int *decoration = ({HEAD_TYPE,NECK_TYPE,ARMOR_TYPE,WAIST_TYPE,BOOTS_TYPE});
        string *nFamily = ({"ÌÒ»¨Ô´", "ÊñÉ½", "½ûÎÀ¾ü", "ÌÆÃÅ", "Ã©É½", "À¥ÂØÉ½", "ÔÆÃÎÔó", });
	string *nTmp;
	object item;
	rand = random(10000);
	id = player->get_number();
	if(sizeof_inventory(player, 1, MAX_CARRY) >= MAX_CARRY )
	{
		send_user(player,"%c%s",'!',"ÄãÉíÉÏµÄµÀ¾ßÀ¸¿Õ¼ä²»¹»£¬ÎŞ·¨ÁìÈ¡½±Àø£¬ºÜ±§Ç¸£¬ÏÂ´Î¶Ò»»½±ÀøÊ±¿ÉÒª×¢ÒâÅ¶¡£");
		return;
	}
	if ( give_yuebing(player,"Ğ¡ÔÂÍÃ",1) == 0 )
        {
		send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf("%s£º\n   ºÜ±§Ç¸£¬ÄãºÃÏñ±»Ã»ÓĞ²¶×½µ½ÔÂÍÃ¡£\n"ESC"È·¶¨",npc->get_name()));
		return ;        			
        }
//        YUTU->add_2(sprintf("player.%d.rabbit",id),1);//Ôö¼Ó¸ÃÍæ¼ÒµÄÅÅĞĞ°ñÍÃ×ÓÊıÁ¿¡£
	if(rand < 2000)
	{
		move_to_user(player, 1, YUEBING,npc);//ÔÂ±ı¡£
	}
	else if(rand < 4000)
	{

		move_to_user(player, 1, "item/91/9102",npc);//Ôì»¯µ¤¡£		
	}
	else if(rand < 6000)
	{
		move_to_user(player, 1, "item/91/9112",npc);//²¹ĞÄµ¤¡£		
	}
	else if(rand < 7000)
	{
		move_to_user(player, 1, "item/91/9120",npc);//¾È¼±µ¤¡£		
	}
	else if(rand < 8000)
	{
		move_to_user(player, 1, "item/91/9121",npc);//»îĞÄµ¤¡£
	}
	else if(rand < 9900)//10000½ğÇ®
	{
		player->add_cash(10000);
		USER_D->user_channel("¹§Ï²"+player->get_name()+"ÔÚÖĞÇï½Ú»î¶¯ÖĞ»ñµÃ"+HIR"10000½ğÇ®"+"¡£\n");
	}
	else if(rand < 9990)//Ëæ»úÃÅÅÉµÄ½ğÉ«×°±¸1¼ş¡£
	{
		if ( (level=player->get_level()+5) >= 120 ) level=120;
		nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],random(2),level,decoration[random(sizeof(decoration))]);
		if ( sizeof(nTmp) )
		{	
			item = new(nTmp[random(sizeof(nTmp))]);
			if ( !item )
				return;
			ITEM_EQUIP_D->init_equip_prop_3(item);
		}
		move = item->move(player,-1);
		if(move)
		{
			item->add_to_user(move);
			USER_D->user_channel("¹§Ï²"+player->get_name()+"ÔÚÖĞÇï½Ú»î¶¯ÖĞ»ñµÃ"+HIR+item->get_name()+"¡£\n");
		}	
		else
			destruct(item);
	}
	else //Ëæ»úÃÅÅÉµÄ½ğÉ«ÎäÆ÷1¼ş
	{
		if ( (level=player->get_level()+5) >= 120 ) level=120;
		nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],random(2),level,WEAPON_TYPE);
		if ( sizeof(nTmp) )
		{	
			item = new(nTmp[random(sizeof(nTmp))]);
			if ( !item )
				return;
			ITEM_EQUIP_D->init_equip_prop_3(item);
		}
		move = item->move(player,-1);
		if(move)
		{
			item->add_to_user(move);
			USER_D->user_channel("¹§Ï²"+player->get_name()+"ÔÚÖĞÇï½Ú»î¶¯ÖĞ»ñµÃ"+HIR+item->get_name()+"¡£\n");
		}	
		else
			destruct(item);
	}
	if( get_party_time() > iFinish ) 
		send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"£º\n"+"    Ğ»Ğ»ÄãµÄ°ïÃ¦£¬ÕâÊÇ¸øÄãµÄ½±Àø¡£\n"+ESC"È·¶¨\n");
	else
		send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"£º\n"+"    Ğ»Ğ»ÄãµÄ°ïÃ¦£¬ÕâÊÇ¸øÄãµÄ½±Àø£¬ÄãµÄ×¥ÍÃÊıÁ¿ÎÒÒÑ¾­¼ÇÏÂÁË£¬Çë¼ÌĞøÅ¬Á¦°É¡£\n"+ESC"È·¶¨\n");
}

void before_destruct()
{
	if ( objectp(change) )
	{
		change->remove_from_scene();
		destruct(change);
	}
}

//½»»¹ÔÂÍÃ£¬»ñµÃ½ğÉ«×°±¸»òÕß½ğÉ«ÎäÆ÷¡£
/*void equipment(string*schoolname, int*gender,int*decoration,object player)
{
	int level,move;
	object present; 
	string* gold_equip = ({});
	level = player->get_level();
	level = level+random(10)+1;
	if(level > 120)
	{
		level = 120;
	}
	gold_equip = WEAPON_FILE->get_family_equip(schoolname[random(sizeof(schoolname))],gender[random(sizeof(gender))],level,decoration[random(sizeof(decoration))]);
	if(sizeof(gold_equip)> 0)
	{
		present = new(gold_equip[random(sizeof(gold_equip))]);
		if(!present)
		{
			return;
		}
		ITEM_EQUIP_D->init_equip_prop_3(present);
		if( move = present->move(player, -1) )
	        {
	                present->add_to_user(move);
	                USER_D->user_channel("¹§Ï²"+player->get_name()+"ÔÚÖĞÇï½Ú»î¶¯ÖĞ»ñµÃ"+HIR+present->get_name()+"¡£\n");
	        }
	        else
	        {
	        	destruct(present);
	        }
	}
}*/

//»î¶¯¿ª¹Ø
int get_close()
{
	return close;
}

void set_close()
{
	close=1;
	destruct_chang();
	destroy_yutu();
	destroy_yuebing();
}