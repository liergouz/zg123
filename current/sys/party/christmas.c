/*****************************
	**圣诞节**
*****************************/

#include <time.h>
#include <ansi.h>
#include <cmd.h>
#define SANTACLAUS	"npc/party/santaclaus"
#define TURKEY		"item/04/0413"
#define SANTANBADMAN		"npc/party/0012"

int *nScene = ({1,10,20,30,40,50,60,70});
int iStart,iFinish;
object SantaClaus,SantaBear,SantaGuan,SantaFeizei;
mapping mpTree1 = ([
1:({  ({53,144}),  }),
80:({  ({292,183}),  }),
//886:({  ({93,127}),  }),
]);
mapping mpTree2 =  ([
1:({  ({193,148}),({146,153}),({182,153}),  }),
10:({  ({130,113}), ({135,117}) , ({139,198}),({143,195}) }),
20:({  ({228,84}),({167,87}),({172,93}),({230,93}),  }),
30:({  ({191,80}),({173,94}),({229,96}),({202,78}),  }),
40:({  ({270,113}),({265,117}),({258,191}),({264,196}),  }),
50:({  ({128,114}),({134,118}),({118,172}),  }),
60:({  ({242,169}),({247,173}),({138,184}),({133,188}),  }),
70:({  ({181,219}),({251,187}),({217,245}),({232,217}),  }),
80:({  ({220,49}),({189,70}),({161,75}),({214,117}),({209,121}),({323,134}),  }),
289:({  ({49,59}), ({66,62}) }),
165:({  ({90,30}), ({110,30}) }),
269:({  ({253,166}), ({265,188}) }),
273:({  ({185,140}),({197,155}),({216,170}),  }),
54:({  ({140,115}),({127,126}),({114,138}),  }),
324:({  ({99,115}), ({119,156}) }),
886:({  ({112,92}), ({136,110}) }),
]);

int SantaClausGift(object me, object who);
int check_turkey(object who, int count);
int give_turkey(object who, int count);
void generate_turkey();
void generate_badman();
void destroy_badman();
void generate_tree();

// 函数：生成二进制码
void SAVE_BINARY() { }

void create()
{
//	iStart = mktime(2006,12,23,10,0,0);	
//	iFinish = mktime(2006,12,28,0,0,0);	
//	call_out("check_time",3);
//	generate_tree();
	iStart = mktime(2007,1,3,0,0,0);	
	iFinish = mktime(2007,1,8,0,0,0);	
}

void check_time()
{
	int iHour,p;
	mixed *mixTime;

	remove_call_out("check_time");
	iHour = time();
	if ( iHour > iFinish )
		return ;
	if ( iHour < iStart )
	{
		call_out("check_time",iStart-iHour);
		return ;
	}
	if ( !objectp(SantaClaus) )
	{
		SantaClaus = new(SANTACLAUS);
		SantaClaus->add_to_scene(80,285,176,4);
	}
	if ( !objectp(SantaBear) )
	{
		SantaBear = new("npc/party/santabear");
		SantaBear->add_to_scene(80,287,178,4);
	}
	if ( !objectp(SantaGuan) )
	{
		SantaGuan = new("npc/party/santaguan");
		SantaGuan->add_to_scene(80,286,179,4);
	}
	if ( !objectp(SantaFeizei) )
	{
		SantaFeizei = new("npc/party/santafeizei");
		SantaFeizei->add_to_scene(80,288,177,4);
	}		
	mixTime = localtime(time());
	iHour = mixTime[TIME_HOUR];
	if ( mixTime[TIME_MIN] >= 30 )
		call_out("check_time",60*(60-mixTime[TIME_MIN]));
	else
		call_out("check_time",60*(30-mixTime[TIME_MIN]));

	
	if ( iHour >= 19 )	//放火鸡
	{
		if ( SANTACLAUS->get("turkey") !=  time()/1800 )
		{
			SANTACLAUS->set("turkey",time()/1800);
			generate_turkey();
		}
	}
	if ( iHour == 10 || iHour == 15 || iHour == 19 || iHour == 22 )	//刷新恶人
	{
		if ( SANTACLAUS->get("banman") != iHour )
		{
			generate_badman();
			SANTACLAUS->set("banman",iHour);
		}
	}
	else if ( iHour == 12 || iHour == 17 || iHour == 21 || iHour == 0 )
	{
		destroy_badman();
	}
	
}

void before_destruct()
{
	int i,size;
	object *nObj;
	if ( objectp(SantaClaus) )
	{
		SantaClaus->remove_from_scene();
		destruct(SantaClaus);
	}
	if ( objectp(SantaBear) )
	{
		SantaBear->remove_from_scene();
		destruct(SantaBear);
	}
	if ( objectp(SantaGuan) )
	{
		SantaGuan->remove_from_scene();
		destruct(SantaGuan);
	}
	if ( objectp(SantaFeizei) )
	{
		SantaFeizei->remove_from_scene();
		destruct(SantaFeizei);
	}		
	nObj = SANTACLAUS->get("tree");
	for(i=0,size=sizeof(nObj);i<size;i++)
	{
		if ( !objectp(nObj[i]) )continue;
		nObj[i]->remove_from_scene();
		destruct(nObj[i]);
	}

}

void do_look(object me,object who)
{
	int id = getoid(me),i;
	i = time();
//	if ( i >iStart && i < iFinish )
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    一年一度的圣诞盛事到来，我——圣诞老人可为你们准备了很多礼物哦！\n    带好你们的长统袜，来我这装礼物吧！\n    长统袜可以通过消灭国家城外那些抢走我礼物的圣诞怪兽获得，对了，城外的那些圣诞火鸡也可以拿来换圣诞礼物哦！\n"ESC"长统袜\ntalk %x# welcome.1\n"ESC"火鸡的兑换\ntalk %x# welcome.2\n"ESC"离开",me->get_name(),id,id));
		
}

void do_welcome( object me, string arg )
{
	int flag,i,rate,exp,money,pot;
	int id = getoid(me);
       	object who,item,player,gift;  
       	string name,cTmp,id1; 
	mixed *mixTime;
        who = this_player();
        if ( sscanf(arg,"%d.%s",flag,id1) != 2 )
        	flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
//        case 1:
//		if( !objectp( item = present("长统袜", who, 1, MAX_CARRY) ) || item->is_christmas() != 1 )
//        	{
//			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    难道你没有看见吗？那些在国家城外的圣诞笨熊、圣诞罐妖、圣诞飞贼，都是抢走我礼物的怪兽，你去七国城外（除周国）好好找找吧，能替我找回袜子，我一定送你一份大礼！\n"ESC"离开",me->get_name()));
//        		return ;	
//        	}
//        	item->add_amount(-1);
//		if ( SantaClausGift(me,who) != 1 )
//			item->add_amount(1);
//        	break;
//        case 2:
//		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    圣诞火鸡，我的最爱～\n    你拿火鸡给我，我会给你圣诞节礼物的！\n"ESC"5只火鸡兑换神秘礼物\ntalk %x# welcome.3\n"ESC"离开",me->get_name(),getoid(me)));
//		break;
//	case 3:
//		if ( check_turkey(who,5) != 1 )
//		{
//			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你身上的圣诞火鸡好象不多嘢。建议你到其他国家的城外走走，说不定有意外惊喜呢～\n"ESC"离开",me->get_name()));
//        		return ;
//		}
//		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
//        			return ;
//        	give_turkey(who,5);
//		SantaClausGift(me,who);
//        	break;
        case 4:
        	if ( time() > iFinish )
        		return ;
        	if ( time() < iStart )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    呵～呵～呵～呵～，虽然圣诞节已经过去了，但身为专业的圣诞老人我可不能就这样闲着。为了感谢大家对大话战国测试工作的支持，只要你的等级达到50级以上，从本月4日到7日这段时间内到我这里便可以领取丰厚的礼物。\n",me->get_name()));
        		return ;
        	}
		if ( who->get_save("20070104gift") )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    做人可不能贪心哟，你之前已经领取过礼物了，还想要的话请耐心等待下次机会吧。\n",me->get_name()));
        		return ;
        	}
        	if ( who->get_level() < 50 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你的等级还没达到50级，按照规矩我还不能送礼物给你。\n",me->get_name()));
        		return ;
        	}
        	if ( TASK_LEGEND_D->can_carry_amount(who,8) != 1 )
			return ;
		TASK_LEGEND_D->give_item(who,BOOK_FILE->get_book_file(),1);     //随机技能进阶书
		TASK_LEGEND_D->give_item(who,"/item/sell/0007",5);     		//速效小治愈药水×5
		TASK_LEGEND_D->give_item(who,"/item/sell/0009",5);     		//速效小恢复药水×5
		TASK_LEGEND_D->give_item(who,"/item/sell/0002",1);     		//大血石×1
		TASK_LEGEND_D->give_item(who,"/item/sell/0004",1);     		//大法石×1
		TASK_LEGEND_D->give_item(who,"/item/sell/0006",5);     		//人参×5
		TASK_LEGEND_D->give_item(who,"/item/sell/0012",5);     		//友情呼唤×5
		TASK_LEGEND_D->give_item(who,"/item/44/4404",1);     		//玉灵液×1
		who->set_save("20070104gift",1);
        	send_user(who,"%c%s",';',"你得到 随机技能进阶书一本、速效小治愈药水×5、速效小恢复药水×5、大血石×1、大法石×1、人参×5、友情呼唤×5、玉灵液×1");
        	break;
        	break;
        }
}
//检查火鸡数量
int check_turkey(object who, int count)
{
	int i,size,amount;
	object *inv,item;	
	string name="圣诞火鸡";
	inv = all_inventory(who, 1, MAX_CARRY);
	
	if( !objectp( item = present(name, who, 1, MAX_CARRY) ) || item->is_christmas() != 1 )
	{
		return 0;	
	}			
	for(i=0,size=sizeof(inv);i<size;i++)
	{
		if ( !objectp(inv[i]) )
			continue;
		if ( inv[i]->get_name() != name || inv[i]->is_christmas() != 1 )
			continue;
		if ( inv[i]->is_combined() )
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
//给予火鸡
int give_turkey(object who, int count)
{
	int i,size,amount;
	object *inv,item;	
	string name="圣诞火鸡";
	if ( check_turkey(who,count) != 1 )
		return 0;
	inv = all_inventory(who, 1, MAX_CARRY);
	for(i=0,size=sizeof(inv);i<size;i++)
	{
		if ( !objectp(inv[i]) )
			continue;
		if ( inv[i]->get_name() != name || inv[i]->is_christmas() != 1 )
			continue;
		amount = inv[i]->get_amount();
		if ( count >= amount )
		{
			inv[i]->remove_from_user();
			destruct(inv[i]);
			count -= amount;
		}
		else
		{
			inv[i]->add_amount(-count);
			count = 0;	
		}
		if ( count <= 0 )
			break;
	}
	return 1;		
	
}
//圣诞礼物
int SantaClausGift(object me, object who)
{
	int rate,p,exp,pot,money;
	object gift;
	string name;
	
	rate = random(10000);
	if ( rate < 2000 )
	{
		exp = 400;
	}
	else if ( rate < 4000 )
	{
		pot = 30;
	}
	else if ( rate < 4010 )
	{
		gift = new("item/08/0001");
		name = "战国令";
	}
	else if ( rate < 4040 )
	{
		gift = new("item/08/0002");
		name = "战国号角";
	}
	else if ( rate < 4060 )
	{
		gift = new("item/08/0003");
		name = "血石";
	}
	else if ( rate < 4090 )
	{
		gift = new("item/08/0004");
		name = "法石";
	}
	else if ( rate < 4120 )	//技能进阶书
	{
		gift = new(BOOK_FILE->get_book_file());
		name = gift->get_name();
	}
	else if ( rate < 6120 )
	{
		money = 1000;
	}
	else if ( rate < 6125 )
	{
		gift = new("item/std/6001");
		name = "百宝囊";
	}
	else if ( rate < 6140 )
	{
		gift = new("item/91/9178");
		name = "复生丹";
	}
	else if ( rate < 6300 )		//1级晶石
	{
		gift = new(STONE_FILE->get_diamond_file());
		gift->set_level(1);
	}
	else if ( rate < 7800 )		//藏宝图
	{
		gift = new("item/std/8000");
	}
	else if ( rate < 8100 )	//圣诞树种子
	{
		gift = new("item/04/0414");
	}
	else if ( rate < 8500 )	//变身卡
	{
		switch(random(3))
		{
		default:
			gift = new("item/04/0415");
			break;
		case 1:
			gift = new("item/04/0416");
			break;
		case 2:
			gift = new("item/04/0417");
			break;	
		}		
	}
	else if ( rate < 9250 )	//炼丹成品
	{
		p = random(6);
		switch(p)
		{
		default:	
			gift = new("item/final/91/1808");	//银杏子
			break;
		case 1:	
			gift = new("item/final/91/1809");	//仙山灵芝
			break;
		case 2:	
			gift = new("item/final/91/1810");	//紫箐丹
			break;
		case 3:	
			gift = new("item/final/91/1811");	//舍利子
			break;
		case 4:	
			gift = new("item/std/5211");		//鹤顶红
			gift->set_amount(3);
			break;
		case 5:	
			gift = new("item/91/9145");		//清心丹
			gift->set_amount(2);
			break;										
		}
	}
	else			//机关中成品
	{
		p = random(4);
		switch(p)
		{
		default:	
			gift = new("item/final/16/1607");	//铁制机关构件
			break;
		case 1:	
			gift = new("item/final/16/1612");	//精铁机关构件
			break;
		case 2:	
			gift = new("item/final/16/1609");	//永动核心
			break;
		case 3:	
			gift = new("item/final/16/1610");	//传动机构
			break;
		}
	}
	if ( gift )
	{
		p = gift->move(who,-1);
		if ( !p ) 
		{
			destruct(gift);
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您身上不够空间放我送给您的礼物，建议您清空了再来找我哦～\n"ESC"离开",me->get_name()));
			return 0;	
		}
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你已经获得了我送出的圣诞节礼物，"HIR"%s"NOR"，祝你圣诞节快乐哦～\n"ESC"离开",me->get_name(),gift->get_name()));
		gift->add_to_user(p);	
		if ( name )
        		CHAT_D->sys_channel(0,sprintf(HIR"恭喜%s获得圣诞礼物%s！",who->get_name(),name));
	}
	else if (  money )
	{
		who->add_cash(money);
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你已经获得了我送出的圣诞节礼物，"HIR"%d金"NOR"，祝你圣诞节快乐哦～\n"ESC"离开",me->get_name(),money));
	}
	else if (  pot )
	{
		who->add_potential(pot);
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你已经获得了我送出的圣诞节礼物，"HIR"%d点潜能"NOR"，祝你圣诞节快乐哦～\n"ESC"离开",me->get_name(),pot));
	}
	else if (  exp )
	{
		who->add_exp(exp);
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你已经获得了我送出的圣诞节礼物，"HIR"%d点经验"NOR"，祝你圣诞节快乐哦～\n"ESC"离开",me->get_name(),exp));
	}	
	return 1;
}

void destroy_turkey()
{
	int i,size;
	object *nObj;	
	nObj = SANTACLAUS->get("item");
	for(i=0,size=sizeof(nObj);i<size;i++)
	{
		if ( !objectp(nObj[i]) )
			continue;
		if ( get_d(nObj[i]) )
			continue;
		nObj[i]->remove_from_scene();
		destruct(nObj[i]);
	}
	SANTACLAUS->delete("item");
}

void generate_turkey()
{
	int i,size,z,p,x,y,j,count;
	object *nObj,item;
	
	destroy_turkey();
	nObj = ({});
	for(j=0,count=sizeof(nScene);j<count;j++)
	{
		z = nScene[j];
		for(i=0;i<100;i++)
		{
			if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) )
				continue;
			x = ( p % 1000000 ) / 1000;  y = p % 1000;
			item = new(TURKEY);
			if ( !objectp(item) )
				continue;
			item->add_to_scene(z,x,y);	
			nObj += ({ item });
//log_file("christmas.txt",sprintf("%s %d %d %d %d\n",short_time(),i,z,x,y));	
		}
	}
log_file("christmas.txt",short_time() + " 放火鸡\n" );
	SANTACLAUS->set("item",nObj);
	CHAT_D->sys_channel(0,HIR"圣诞老人坐着雪橇在战国大地撒下热呼呼的圣诞火鸡，大家快快寻找吧～同时圣诞老人祝大家圣诞节快乐。");
	CHAT_D->sys_channel(0,HIG"圣诞老人坐着雪橇在战国大地撒下热呼呼的圣诞火鸡，大家快快寻找吧～同时圣诞老人祝大家圣诞节快乐。");
	CHAT_D->sys_channel(0,HIY"圣诞老人坐着雪橇在战国大地撒下热呼呼的圣诞火鸡，大家快快寻找吧～同时圣诞老人祝大家圣诞节快乐。");
}

void generate_badman()
{
	int i,size,z,p,x,y;
	object *nObj,npc;

	nObj = ({});
	for(z=10;z<=70;z+=10)
	{
		for(i=0;i<50;i++)
		{
			if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) )
				continue;
			x = ( p % 1000000 ) / 1000;  y = p % 1000;
			npc = new(SANTANBADMAN);
			if ( !objectp(npc) )
				continue;
			switch(random(3))
			{
			default:
				npc->set_name("圣诞笨熊");
				npc->set_char_picid(1289);
				npc->set_max_hp(1);
				npc->set_ap(1);
				npc->set_dp(1);
				npc->set_cp(1);
				npc->set_pp(1);
				npc->set_sp(1);
				npc->set_walk_speed(4);  
				npc->set_attack_speed(3);
				break;	
			case 1:
				npc->set_name("圣诞罐妖");
				npc->set_char_picid(1291);
				npc->set_max_hp(10);
				npc->set_ap(1);
				npc->set_dp(1);
				npc->set_cp(1);
				npc->set_pp(1);
				npc->set_sp(1);
				npc->set_walk_speed(2);  
				npc->set_attack_speed(3);
				break;
			case 2:
				npc->set_name("圣诞飞贼");
				npc->set_char_picid(1290);
				npc->set_max_hp(1);
				npc->set_ap(1);
				npc->set_dp(1);
				npc->set_cp(1);
				npc->set_pp(1);
				npc->set_sp(1);
				npc->set_walk_speed(2);  
				npc->set_attack_speed(1);
				break;								
			}
			npc->add_to_scene(z,x,y);	
			nObj += ({ npc });
//log_file("christmas.txt",sprintf("%s %d %d %d %d\n",short_time(),i,z,x,y));	
		}
	}
log_file("christmas.txt",short_time() + " 放圣诞恶人\n" );
	SANTACLAUS->set("npc",nObj);
	CHAT_D->sys_channel(0,HIR"圣诞老人的拉车麋鹿喝了太多的郎姆酒，被一群圣诞恶人抢走了圣诞礼品袋，击杀七国城外的圣诞笨熊、圣诞罐妖、圣诞飞贼，得到的长统袜可以向圣诞老人换礼物哦。");
}

void destroy_badman()
{
	int i,size,z,p,x,y;
	object *nObj,npc;

	nObj = 	SANTACLAUS->get("npc");
	for(i=0,size=sizeof(nObj);i<size;i++)
	{
		if ( !objectp(nObj[i])	)
			continue;
		nObj[i]->remove_from_scene();
		destruct(nObj[i]);
	}
	SANTACLAUS->delete("npc");
}
//逃离
void away_user(object me,object who)
{
	int x,y,z,x0,y0,z0,p,d;
	string cmd;

        z = get_z(who);  x = get_x(who);  y = get_y(who);
        z0 = get_z(me);x0 = get_x(me);  y0 = get_y(me); 
        d = distance_between(me, who);

        if( x0 > x )
        {
                if( y0 > y )
                {
                        if( p = get_valid_path( z, x0, y0, (x + (d+1+random(3))), y + (d+1+random(3)) ) ) ;
                        else if( p = get_valid_path( z, x0, y0, x, y + (d+1+random(3)) ) ) ;
                        else if( p = get_valid_path( z, x0, y0, (x + (d+1+random(3))), y ) ) ;
                        else if( p = get_valid_path( z, x0, y0, (x - (d+1+random(3))), y + (d+1+random(3)) ) ) ;
                        else if( p = get_valid_path( z, x0, y0, (x + (d+1+random(3))), y - (d+1+random(3)) ) ) ;
                }
                else if( y0 == y )
                {
                        if( p = get_valid_path( z, x0, y0, (x + (d+1+random(3))), y ) ) ;
                        else if( p = get_valid_path( z, x0, y0, (x + (d+1+random(3))), y + (d+1+random(3)) ) ) ;
                        else if( p = get_valid_path( z, x0, y0, (x + (d+1+random(3))), y - (d+1+random(3)) ) ) ;
                        else if( p = get_valid_path( z, x0, y0, x, y + (d+1+random(3)) ) ) ;
                        else if( p = get_valid_path( z, x0, y0, x, y - (d+1+random(3)) ) ) ;
                }
                else
                {
                        if( p = get_valid_path( z, x0, y0, (x + (d+1+random(3))), y - (d+1+random(3)) ) ) ;
                        else if( p = get_valid_path( z, x0, y0, (x + (d+1+random(3))), y ) ) ;
                        else if( p = get_valid_path( z, x0, y0, x, y - (d+1+random(3)) ) ) ;
                        else if( p = get_valid_path( z, x0, y0, (x + (d+1+random(3))), y + (d+1+random(3)) ) ) ;
                        else if( p = get_valid_path( z, x0, y0, (x - (d+1+random(3))), y - (d+1+random(3)) ) ) ;
                }
        }
        else if( x0 == x )
        {
                if( y0 > y )
                {
                        if( p = get_valid_path( z, x0, y0, x, y + (d+1+random(3)) ) ) ;
                        else if( p = get_valid_path( z, x0, y0, (x - (d+1+random(3))), y + (d+1+random(3)) ) ) ;
                        else if( p = get_valid_path( z, x0, y0, (x + (d+1+random(3))), y + (d+1+random(3)) ) ) ;
                        else if( p = get_valid_path( z, x0, y0, (x - (d+1+random(3))), y ) ) ;
                        else if( p = get_valid_path( z, x0, y0, (x + (d+1+random(3))), y ) ) ;
                }
                else if( y0 == y ) ;
                else
                {
                        if( p = get_valid_path( z, x0, y0, x, y - (d+1+random(3)) ) ) ;
                        else if( p = get_valid_path( z, x0, y0, (x + (d+1+random(3))), y - (d+1+random(3)) ) ) ;
                        else if( p = get_valid_path( z, x0, y0, (x - (d+1+random(3))), y - (d+1+random(3)) ) ) ;
                        else if( p = get_valid_path( z, x0, y0, (x + (d+1+random(3))), y ) ) ;
                        else if( p = get_valid_path( z, x0, y0, (x - (d+1+random(3))), y ) ) ;
                }
        }
        else
        {
                if( y0 > y )
                {
                        if( p = get_valid_path( z, x0, y0, (x - (d+1+random(3))), y + (d+1+random(3)) ) ) ;
                        else if( p = get_valid_path( z, x0, y0, (x - (d+1+random(3))), y ) ) ;
                        else if( p = get_valid_path( z, x0, y0, x, y + (d+1+random(3)) ) ) ;
                        else if( p = get_valid_path( z, x0, y0, (x - (d+1+random(3))), y - (d+1+random(3)) ) ) ;
                        else if( p = get_valid_path( z, x0, y0, (x + (d+1+random(3))), y + (d+1+random(3)) ) ) ;
                }
                else if( y0 == y )
                {
                        if( p = get_valid_path( z, x0, y0, (x - (d+1+random(3))), y ) ) ;
                        else if( p = get_valid_path( z, x0, y0, (x - (d+1+random(3))), y - (d+1+random(3)) ) ) ;
                        else if( p = get_valid_path( z, x0, y0, (x - (d+1+random(3))), y + (d+1+random(3)) ) ) ;
                        else if( p = get_valid_path( z, x0, y0, x, y - (d+1+random(3)) ) ) ;
                        else if( p = get_valid_path( z, x0, y0, x, y + (d+1+random(3)) ) ) ;
                }
                else
                {
                        if( p = get_valid_path( z, x0, y0, (x - (d+1+random(3))), y - (d+1+random(3)) ) ) ;
                        else if( p = get_valid_path( z, x0, y0, x, y - (d+1+random(3)) ) ) ;
                        else if( p = get_valid_path( z, x0, y0, (x - (d+1+random(3))), y ) ) ;
                        else if( p = get_valid_path( z, x0, y0, (x + (d+1+random(3))), y - (d+1+random(3)) ) ) ;
                        else if( p = get_valid_path( z, x0, y0, (x - (d+1+random(3))), y + (d+1+random(3)) ) ) ;
                }
        }
	
        if( p )    // 找到可走路径
        {
                cmd = sprintf("%d", p);

                switch( me->get_walk_step() )
                {
               case 0 :
               case 1 : if( strlen(cmd) > 1 ) cmd = cmd[0..0];  break;
               case 2 : if( strlen(cmd) > 2 ) cmd = cmd[0..1];  break;
              default : break;
                }
                GO_CMD->main_npc(me, cmd);
        }
}
//放圣诞树
void generate_tree()
{
	int i,size,z,p,x,y,j,count,*nZ,*nXy;
	object *nObj,tree;
	mixed *nPoint;
	nObj = ({});

	nZ = keys(mpTree1);
	for(j=0,count=sizeof(nZ);j<count;j++)
	{
		z = nZ[j];
		nPoint = mpTree1[z];
		for(i=0,size=sizeof(nPoint);i<size;i++)
		{
			tree = new("npc/party/santatree1");
			if ( !objectp(tree) )
				continue;
			nXy = nPoint[i];
			tree->add_to_scene(z,nXy[0],nXy[1]);	
			nObj += ({ tree });
		}
	}
	
	nZ = keys(mpTree2);
	for(j=0,count=sizeof(nZ);j<count;j++)
	{
		z = nZ[j];
		nPoint = mpTree2[z];
		for(i=0,size=sizeof(nPoint);i<size;i++)
		{
			tree = new("npc/party/santatree2");
			if ( !objectp(tree) )
				continue;
			nXy = nPoint[i];
			tree->add_to_scene(z,nXy[0],nXy[1]);	
			nObj += ({ tree });
		}
	}
	
	SANTACLAUS->set("tree",nObj);
}

void test()
{
//	int i,size;
//	object *nObj;
//	
//	nObj = SANTACLAUS->get("plant");
//	for(i=0,size=sizeof(nObj);i<size;i++)
//	{
//		if ( !objectp(nObj[i]) ) continue;
//		nObj[i]->remove_from_scene();
//		destruct(nObj[i]);
//	}
	
}