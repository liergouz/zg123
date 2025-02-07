
#include <ansi.h>
#include <equip.h>

// 函数：生成二进制码
void SAVE_BINARY() { }

string *RankTable = ({
        HIW "不堪一击" NOR, HIB "不堪一击" NOR, HIY "不堪一击" NOR,
        HIW "毫不足虑" NOR, HIB "毫不足虑" NOR, HIY "毫不足虑" NOR,
        HIW "不足挂齿" NOR, HIB "不足挂齿" NOR, HIY "不足挂齿" NOR,
        HIW "初学乍练" NOR, HIB "初学乍练" NOR, HIY "初学乍练" NOR,
        HIW "初窥门径" NOR, HIB "初窥门径" NOR, HIY "初窥门径" NOR,
        HIW "略知一二" NOR, HIB "略知一二" NOR, HIY "略知一二" NOR,
        HIW "普普通通" NOR, HIB "普普通通" NOR, HIY "普普通通" NOR,
        HIW "粗通皮毛" NOR, HIB "粗通皮毛" NOR, HIY "粗通皮毛" NOR,
        HIW "半生不熟" NOR, HIB "半生不熟" NOR, HIY "半生不熟" NOR,
        HIW "马马虎虎" NOR, HIB "马马虎虎" NOR, HIY "马马虎虎" NOR,
        HIW "略有小成" NOR, HIB "略有小成" NOR, HIY "略有小成" NOR,
        HIW "驾轻就熟" NOR, HIB "驾轻就熟" NOR, HIY "驾轻就熟" NOR,
        HIW "心领神会" NOR, HIB "心领神会" NOR, HIY "心领神会" NOR,
        HIW "了然於胸" NOR, HIB "了然於胸" NOR, HIY "了然於胸" NOR,
        HIW "略有大成" NOR, HIB "略有大成" NOR, HIY "略有大成" NOR,
        HIW "豁然贯通" NOR, HIB "豁然贯通" NOR, HIY "豁然贯通" NOR,
        HIW "出类拔萃" NOR, HIB "出类拔萃" NOR, HIY "出类拔萃" NOR,
        HIW "技冠群雄" NOR, HIB "技冠群雄" NOR, HIY "技冠群雄" NOR,
        HIW "神乎其技" NOR, HIB "神乎其技" NOR, HIY "神乎其技" NOR,
        HIW "出神入化" NOR, HIB "出神入化" NOR, HIY "出神入化" NOR,
        HIW "一代宗师" NOR, HIB "一代宗师" NOR, HIY "一代宗师" NOR,
        HIW "傲视群雄" NOR, HIB "傲视群雄" NOR, HIY "傲视群雄" NOR,
        HIW "神功盖世" NOR, HIB "神功盖世" NOR, HIY "神功盖世" NOR,
        HIW "登峰造极" NOR, HIB "登峰造极" NOR, HIY "登峰造极" NOR,
        HIW "举世无双" NOR, HIB "举世无双" NOR, HIY "举世无双" NOR,
        HIW "一代天骄" NOR, HIB "一代天骄" NOR, HIY "一代天骄" NOR,
        HIW "盖世奇才" NOR, HIB "盖世奇才" NOR, HIY "盖世奇才" NOR,
        HIW "旷世高手" NOR, HIB "旷世高手" NOR, HIY "旷世高手" NOR,
        HIW "惊世骇俗" NOR, HIB "惊世骇俗" NOR, HIY "惊世骇俗" NOR,
        HIW "震古铄今" NOR, HIB "震古铄今" NOR, HIY "震古铄今" NOR,
        HIW "空前绝后" NOR, HIB "空前绝后" NOR, HIY "空前绝后" NOR,
        HIW "深不可测" NOR, HIB "深不可测" NOR, HIY "深不可测" NOR,
        HIW "神出鬼没" NOR, HIB "神出鬼没" NOR, HIY "神出鬼没" NOR,
        HIW "超凡入圣" NOR, HIB "超凡入圣" NOR, HIY "超凡入圣" NOR,
        HIW "返璞归真" NOR, HIB "返璞归真" NOR, HIY "返璞归真" NOR,
        HIW "天人合一" NOR, HIB "天人合一" NOR, HIY "天人合一" NOR,
        HIW "随心所欲" NOR, HIB "随心所欲" NOR, HIY "随心所欲" NOR,
        HIW "平淡无奇" NOR, HIB "平淡无奇" NOR, HIY "平淡无奇" NOR,
});

mapping mpTimeRank = ([
	1 : ({ 8, "初级奖励" }),
	2 : ({ 10, "初级奖励" }),
	3 : ({ 12, "初级奖励" }),
	4 : ({ 14, "初级奖励" }),
	5 : ({ 16, "初级奖励" }),
	6 : ({ 18, "中级奖励" }),
	7 : ({ 20, "初级奖励" }),
	8 : ({ 22, "中级奖励" }),
	9 : ({ 24, "中级奖励" }),
	10 : ({ 26, "中级奖励" }),
	11 : ({ 28, "中级奖励" }),
	12 : ({ 30, "中级奖励" }),
	13 : ({ 32, "中级奖励" }),
	14 : ({ 34, "中级奖励" }),
	15 : ({ 36, "中级奖励" }),
	16 : ({ 38, "高级奖励" }),
	17 : ({ 40, "中级奖励" }),
	18 : ({ 42, "高级奖励" }),
	19 : ({ 44, "中级奖励" }),
	20 : ({ 46, "高级奖励" }),
	21 : ({ 48, "中级奖励" }),
	22 : ({ 50, "高级奖励" }),
	23 : ({ 52, "高级奖励" }),
	24 : ({ 54, "高级奖励" }),
	25 : ({ 56, "高级奖励" }),
	26 : ({ 58, "高级奖励" }),
	27 : ({ 60, "特级奖励" }),
	28 : ({ 62, "高级奖励" }),
	29 : ({ 64, "特级奖励" }),
	30 : ({ 66, "高级奖励" }),
	31 : ({ 68, "特级奖励" }),
	32 : ({ 70, "特级奖励" }),
	33 : ({ 72, "特级奖励" }),
	34 : ({ 74, "高级奖励" }),
	35 : ({ 76, "特级奖励" }),
	36 : ({ 78, "特级奖励" }),
	37 : ({ 80, "特级奖励" }),
	38 : ({ 82, "特级奖励" }),
	39 : ({ 84, "高级奖励" }),
	40 : ({ 86, "特级奖励" }),
	41 : ({ 88, "特级奖励" }),
	42 : ({ 90, "特级奖励" }),
	43 : ({ 92, "特级奖励" }),
	44 : ({ 94, "特级奖励" }),
	45 : ({ 96, "特级奖励" }),
	46 : ({ 98, "特级奖励" }),
	47 : ({ 100, "特级奖励" }),
	48 : ({ 102, "特级奖励" }),
	49 : ({ 104, "特级奖励" }),
	50 : ({ 106, "特级奖励" }),
	51 : ({ 108, "特级奖励" }),
	52 : ({ 110, "特级奖励" }),
	53 : ({ 112, "特级奖励" }),
	54 : ({ 114, "特级奖励" }),
	55 : ({ 116, "特级奖励" }),
	56 : ({ 118, "特级奖励" }),
	57 : ({ 120, "特级奖励" }),
	58 : ({ 122, "特级奖励" }),
	59 : ({ 124, "特级奖励" }),
	60 : ({ 126, "特级奖励" }),
	61 : ({ 128, "特级奖励" }),
	62 : ({ 130, "特级奖励" }),
	63 : ({ 132, "特级奖励" }),
	64 : ({ 134, "特级奖励" }),
	65 : ({ 136, "特级奖励" }),
	66 : ({ 138, "特级奖励" }),
	67 : ({ 140, "特级奖励" }),
	68 : ({ 142, "特级奖励" }),
	69 : ({ 144, "特级奖励" }),
	70 : ({ 146, "特级奖励" }),
	71 : ({ 148, "特级奖励" }),
	72 : ({ 150, "特级奖励" }),
	73 : ({ 152, "特级奖励" }),
	74 : ({ 154, "特级奖励" }),
	75 : ({ 156, "特级奖励" }),
	76 : ({ 158, "特级奖励" }),
	77 : ({ 160, "特级奖励" }),
	78 : ({ 162, "特级奖励" }),
	79 : ({ 164, "特级奖励" }),
	80 : ({ 166, "特级奖励" }),
	81 : ({ 168, "特级奖励" }),

]);
int sizeof_rank = sizeof(RankTable);
string *nFamily = ({"桃花源","蜀山","禁卫军","唐门","茅山","昆仑山","云梦泽"});

// 函数：获得能力称谓
string get_rank( object who )
{
        int ap, cp;

        if( !objectp(who) ) return "";

        ap = who->get_ap();
        cp = who->get_cp();
        if( cp > ap ) ap = cp;

        ap = range_value( ap / 30, 0, sizeof_rank - 1 );

        return RankTable[ap];
}

//根据时间获取修为等级
int check_online_level(int hour)
{
	int i,size,*nTmp,level,count;
	mixed *mxTmp;
	
	nTmp = sort_array(keys(mpTimeRank),1);	//升序
	for(i=0,size=sizeof(nTmp);i<size;i++)
	{
		level = nTmp[i];
		mxTmp = mpTimeRank[level];
		count += mxTmp[0];
		if ( count < hour )
			continue;
		if ( count == hour )
			break;
		level --;
		break;
	}
	return level;
}
//
void send_friend_info(object me,int level)
{
        object who;
        mapping Friends;
        string *key,acount,cTmp;
        int i, size,id;

	Friends = me->get_friend_dbase();
        size = sizeof( key = keys(Friends) );
        if( size ) key = sort_array(key, 1);
        cTmp = sprintf(BLK "周王：\n    听说%s玩家的修为又进一步，已经达到了%d级。各位好友祝贺他吧！",me->get_name(),level);
        for( i = 0; i < size; i ++ )
        {
        	id = to_int(key[i]);
                acount = me->get_friend_id(id);
		MAILBOX->sys_mail(acount,id,cTmp);
        }
}
//修为系统
void online_rank(object who,int flag)
{
	int i,level,hour,level1;
	
	if ( "sys/sys/count"->get_new_story() == 0 )
		return ;
	if ( flag == 0 )
	{
		if ( !who->get_save_2("online_rank.time") )	//初始化
		{
			who->set_save_2("online_rank.time",who->get_game_time());
			hour = who->get_game_time()/3600;
			level = check_online_level(hour);
			who->set_save_2("online_rank.level",level);
			USER_ENERGY_D->count_max_hp(who);
		}
		else if ( who->get_save_2("online_rank.time") < who->get_game_time() )	//校正时间
		{
			who->set_save_2("online_rank.time",who->get_game_time());
		}
		else if ( who->get_save_2("online_rank.time") > who->get_game_time() )	//校正时间
		{
			who->set_game_time(who->get_save_2("online_rank.time"));
		}
		who->set_save_2("online_rank.start",time());
		
		return ;
	}
	else if ( flag == 1 )
	{
		i = who->get_save_2("online_rank.start");
		if ( !i )
		{
			who->set_save_2("online_rank.start",time());
			return ;
		}
		i = gone_time(i);
		hour = who->add_save_2("online_rank.time",i)/3600;
		who->set_save_2("online_rank.start",time());
		level = who->get_save_2("online_rank.level");
		level1 = check_online_level(hour);
		if ( level >= level1 )
			return ;
		//修为升级
		who->set_save_2("online_rank.level",level1);
		send_user(who,"%c%c%c",0xA2,10,level1);
		USER_ENERGY_D->count_max_hp(who);
		MAILBOX->sys_mail(who->get_id(),who->get_number(),BLK"周王：\n    	恭喜你修行又进一层，我已经为你预备好了你的修为礼物，在你下次过修为之前，你都可以来周国找我领取你的修为礼物。");
		if ( (level1 % 27) == 0 )
			send_friend_info(who,level1);
	}
		
}
//
varargs int give_item(object who, string cName,int color,int level)
{
	int p;
	object item;
	
	item = new(cName);
	if ( !item )
		return 0;
	p = item->move(who,-1);
	if ( !p )
	{
		send_user(who,"%c%s",'!',"你身上道具栏空位不够");
		destruct(item);
		return 0;
	}
	if ( color == 1 )
		ITEM_EQUIP_D->init_equip_prop_1(item);
	else if ( color == 3 )
		ITEM_EQUIP_D->init_equip_prop_3(item);

	if ( level )
		item->set_level(level);
	item->add_to_user(p);
	send_user(who,"%c%s",';',sprintf("领取礼物成功！你得到"HIR"%s",item->get_name()));
	return 1;
}
//初级奖励
int get_bonus1(object who)
{
	int ret,exp;

	if ( random(2) )
	{
		switch(random(4))
		{
		default:
		case 0:
			ret = give_item(who,"/item/std/6002",0);	//乾坤袋
			break;
		case 1:
			ret = give_item(who,"item/08/0013",0);		//绑定的战国令
			break;
		case 2:
			ret = give_item(who,BOOK_FILE->get_book_file(),0);	//随机进阶技能书
			break;
		case 3:
			ret = give_item(who,COLLECT_FILE->get_collect_file(),0);	//随机收藏品
			break;
		}
		
	}
	else
	{
		switch(random(6))
		{
		default:
		case 0:
			ret = give_item(who,"/item/final/15/1504",0);	//初级法攻
			break;
		case 1:
			ret = give_item(who,"/item/final/15/1502",0);		//初级物攻
			break;
		case 2:
			exp = 100000;
			ret = 1;
			break;
		case 3:
			exp = 80000;
			ret = 1;
			break;
		case 4:
			exp = 60000;
			ret = 1;
			break;			
		case 5:
			ret = give_item(who,"item/44/4404",0);	//玉灵液
			break;
		}		
		
	}
	if ( exp )
	{
		who->add_exp(exp);
		send_user(who,"%c%s",';',sprintf("领取礼物成功！你得到%d经验",exp));
	}
	return ret;
}
//中级奖励
int get_bonus2(object who)
{
	int ret,exp;
        string *nTmp,tmp;

	if ( random(2) )
	{
		switch(random(5))
		{
		default:
		case 0:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,50,HEAD_TYPE+random(6));
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,1);	//50级随机蓝色装备
			break;
		case 1:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,60,HEAD_TYPE+random(6));
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,1);	//60级随机蓝色装备
			break;
		case 2:
			ret = give_item(who,"quest/product2"->get_random_level_product(50,50));	//50级随机蓝色图纸
			break;
		case 3:
			ret = give_item(who,"quest/product2"->get_random_level_product(60,60));	//60级随机蓝色图纸
			break;
		case 4:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,50,WAIST_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,3);	//50级随机金色腰带
			break;
		}
	}
	else
	{
		switch(random(14))
		{
		default:
		case 0:
			//随机高级药品
			switch(random(9))
			{
			default:
			case 0:
				ret = give_item(who,"item/91/9125");
				break;	
			case 1:
				ret = give_item(who,"item/91/9150");
				break;
			case 2:
				ret = give_item(who,"item/91/9160");
				break;
			case 3:
				ret = give_item(who,"item/91/9161");
				break;
			case 4:
				ret = give_item(who,"item/91/9162");
				break;	
			case 5:
				ret = give_item(who,"item/91/9163");
				break;
			case 6:
				ret = give_item(who,"item/91/9164");
				break;
			case 7:
				ret = give_item(who,"item/91/9165");
				break;
			case 8:
				ret = give_item(who,"item/std/0088");
				break;
				
			}
			break;
		case 1:
			ret = give_item(who,STONE_FILE->get_diamond_file(),0,1);	//1级晶石
			break;
		case 2:
			ret = give_item(who,"item/44/4488");	//基础宠物技能丹
			break;	
		case 3:
			ret = give_item(who,sprintf("item/std/%d",8001+random(4)));	//随机残缺藏宝图
			break;	
		case 4:
			ret = give_item(who,"item/91/9167");	//紫参丹
			break;	
		case 5:
			ret = give_item(who,"item/44/4404",0);	//玉灵液
			break;
		case 6:
			ret = give_item(who,"/item/final/15/1504",0);	//初级法攻
			break;
		case 7:
			ret = give_item(who,"/item/final/15/1502",0);		//初级物攻
			break;
		case 8:
			exp = 200000;
			ret = 1;
			break;
		case 9:
			exp = 250000;
			ret = 1;
			break;
		case 10:
			exp = 300000;
			ret = 1;
			break;			
		case 11:
			ret = give_item(who,"item/08/0013",0);		//绑定的战国令
			break;
		case 12:
			ret = give_item(who,"item/91/9178",0);		//复生丹
			break;
		case 13:
			ret = give_item(who,"item/sell/0044",0);	//济世宝玉
			break;
		}		
	}
	if ( exp )
	{
		who->add_exp(exp);
		send_user(who,"%c%s",';',sprintf("领取礼物成功！你得到%d经验",exp));
	}
	return ret;
}
//高级奖励
int get_bonus3(object who)
{
	int ret,exp;
        string *nTmp,tmp;
	if ( random(2) )
	{
		switch(random(13))
		{
		default:
		case 0:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,70,HEAD_TYPE+random(6));
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,1);	//70级蓝色装备
			break;
		case 1:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,80,HEAD_TYPE+random(6));
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,1);	//80级随机蓝色装备
			break;
		case 2:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,90,HEAD_TYPE+random(6));
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,1);	//90级随机蓝色装备
			break;
		case 3:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,70,WEAPON_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,1);	//70级随机蓝色武器
			break;
		case 4:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,80,WEAPON_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,1);	//80级随机蓝色武器
			break;
		case 5:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,70,HEAD_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,3);	//70级随机金色帽子
			break;
		case 6:
			ret = give_item(who,"quest/product2"->get_random_level_product(70,70));	//70级随机蓝色装备图纸
			break;
		case 7:
			ret = give_item(who,"quest/product2"->get_random_level_product(80,80));	//80级随机蓝色图纸
			break;
		case 8:
			ret = give_item(who,"quest/product2"->get_random_level_product(90,90));	//90级随机蓝色图纸
			break;
		case 9:
			ret = give_item(who,"/item/std/6002",0);	//乾坤袋
			break;
		case 10:
			ret = give_item(who,"item/08/0013",0);		//绑定的战国令
			break;
		case 11:
			ret = give_item(who,BOOK_FILE->get_book_file(),0);	//随机进阶技能书
			break;
		case 12:
			ret = give_item(who,COLLECT_FILE->get_collect_file(),0);	//随机收藏品
			break;
		}
	}
	else
	{
		switch(random(15))
		{
		default:
		case 0:
			//随机高级药品
			switch(random(9))
			{
			default:
			case 0:
				ret = give_item(who,"item/91/9125");
				break;	
			case 1:
				ret = give_item(who,"item/91/9150");
				break;
			case 2:
				ret = give_item(who,"item/91/9160");
				break;
			case 3:
				ret = give_item(who,"item/91/9161");
				break;
			case 4:
				ret = give_item(who,"item/91/9162");
				break;	
			case 5:
				ret = give_item(who,"item/91/9163");
				break;
			case 6:
				ret = give_item(who,"item/91/9164");
				break;
			case 7:
				ret = give_item(who,"item/91/9165");
				break;
			case 8:
				ret = give_item(who,"item/std/0088");
				break;
				
			}
			break;
			break;
		case 1:
			ret = give_item(who,STONE_FILE->get_diamond_file(),0,1);	//1级晶石
			break;
		case 2:
			ret = give_item(who,"item/44/4488");	//基础宠物技能丹
			break;	
		case 3:
			ret = give_item(who,sprintf("item/std/%d",8001+random(4)));	//随机残缺藏宝图
			break;	
		case 4:
			ret = give_item(who,"item/91/9167");	//紫参丹
			break;	
		case 5:
			ret = give_item(who,"item/44/4404",0);	//玉灵液
			break;
		case 6:
			ret = give_item(who,"/item/final/15/1504",0);	//初级法攻
			break;
		case 7:
			ret = give_item(who,"/item/final/15/1502",0);		//初级物攻
			break;
		case 8:
			exp = 600000;
			ret = 1;
			break;
		case 9:
			exp = 700000;
			ret = 1;
			break;
		case 10:
			exp = 800000;
			ret = 1;
			break;			
		case 11:
			ret = give_item(who,"item/08/0013",0);		//绑定的战国令
			break;
		case 12:
			ret = give_item(who,"item/91/9178",0);		//复生丹
			break;
		case 13:
			ret = give_item(who,"item/sell/0044",0);	//济世宝玉
			break;
		case 14:
			ret = give_item(who,sprintf("item/sell/%04d",15+random(5)),0);//洗点丸
			break;
		}		
	}
	if ( exp )
	{
		who->add_exp(exp);
		send_user(who,"%c%s",';',sprintf("领取礼物成功！你得到%d经验",exp));
	}
	return ret;
}
//特级奖励
int get_bonus4(object who)
{
	int ret,exp;
        string *nTmp,tmp;

	if ( random(2) )
	{
		switch(random(14))
		{
		default:
		case 0:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,100,HEAD_TYPE+random(6));
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,1);	//100级蓝色装备
			break;
		case 1:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,110,HEAD_TYPE+random(6));
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,1);	//110级随机蓝色装备
			break;
		case 2:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,120,HEAD_TYPE+random(6));
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,1);	//120级随机蓝色装备
			break;
		case 3:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,100,WEAPON_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,1);	//100级随机蓝色武器
			break;
		case 4:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,110,WEAPON_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,1);	//110级随机蓝色武器
			break;
		case 5:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,100,WEAPON_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,3);	//100级随机金色武器
			break;
		case 6:
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,110,BOOTS_TYPE);
        		tmp = nTmp[random(sizeof(nTmp))];
        		if ( !stringp(tmp) )
        			return ;
			ret = give_item(who,tmp,3);	//110级随机金色鞋子
			break;
		case 7:
			ret = give_item(who,"quest/product2"->get_random_level_product(100,100));	//100级随机蓝色装备图纸
			break;
		case 8:
			ret = give_item(who,"quest/product2"->get_random_level_product(110,110));	//110级随机蓝色图纸
			break;
		case 9:
			ret = give_item(who,"quest/product2"->get_random_level_product(120,120));	//120级随机蓝色图纸
			break;
		case 10:
			ret = give_item(who,"/item/std/6002",0);	//乾坤袋
			break;
		case 11:
			ret = give_item(who,"item/08/0013",0);		//绑定的战国令
			break;
		case 12:
			ret = give_item(who,BOOK_FILE->get_book_file(),0);	//随机进阶技能书
			break;
		case 13:
			ret = give_item(who,COLLECT_FILE->get_collect_file(),0);	//随机收藏品
			break;
		}
	}
	else
	{
		switch(random(15))
		{
		default:
		case 0:
			//随机高级药品
			switch(random(9))
			{
			default:
			case 0:
				ret = give_item(who,"item/91/9125");
				break;	
			case 1:
				ret = give_item(who,"item/91/9150");
				break;
			case 2:
				ret = give_item(who,"item/91/9160");
				break;
			case 3:
				ret = give_item(who,"item/91/9161");
				break;
			case 4:
				ret = give_item(who,"item/91/9162");
				break;	
			case 5:
				ret = give_item(who,"item/91/9163");
				break;
			case 6:
				ret = give_item(who,"item/91/9164");
				break;
			case 7:
				ret = give_item(who,"item/91/9165");
				break;
			case 8:
				ret = give_item(who,"item/std/0088");
				break;
			}
			break;
			break;
		case 1:
			ret = give_item(who,STONE_FILE->get_diamond_file(),0,1);	//1级晶石
			break;
		case 2:
			ret = give_item(who,"item/44/4488");	//基础宠物技能丹
			break;	
		case 3:
			ret = give_item(who,sprintf("item/std/%d",8001+random(4)));	//随机残缺藏宝图
			break;	
		case 4:
			ret = give_item(who,"item/91/9167");	//紫参丹
			break;	
		case 5:
			ret = give_item(who,"item/44/4404",0);	//玉灵液
			break;
		case 6:
			ret = give_item(who,"/item/final/15/1504",0);	//初级法攻
			break;
		case 7:
			ret = give_item(who,"/item/final/15/1502",0);		//初级物攻
			break;
		case 8:
			exp = 1000000;
			ret = 1;
			break;
		case 9:
			exp = 1100000;
			ret = 1;
			break;
		case 10:
			exp = 1200000;
			ret = 1;
			break;			
		case 11:
			ret = give_item(who,"item/08/0013",0);		//绑定的战国令
			break;
		case 12:
			ret = give_item(who,"item/91/9178",0);		//复生丹
			break;
		case 13:
			ret = give_item(who,"item/sell/0044",0);	//济世宝玉
			break;
		case 14:
			ret = give_item(who,sprintf("item/sell/%04d",15+random(5)),0);//洗点丸
			break;
		}		
	}
	if ( exp )
	{
		who->add_exp(exp);
		send_user(who,"%c%s",';',sprintf("领取礼物成功！你得到%d经验",exp));
	}
	return ret;
}
//领取修为奖励
void get_rank_bonus(object who,object me)
{
	int level,ret;
	string cTmp;
	
	level = who->get_save_2("online_rank.level");
	if ( !level )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s：\n    你还没有修为等级！\n"ESC"离开", me->get_name(), ) );
		return ;	
	}	
	if ( level == who->get_save_2("online_rank.bonus") )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s：\n    你已经领过礼物了！\n"ESC"离开", me->get_name(), ) );
		return ;	
	}
	cTmp = mpTimeRank[level][1];
	switch(cTmp)
	{
	default:
	case "初级奖励":
		ret = get_bonus1(who);
		break;	
	case "中级奖励":
		ret = get_bonus2(who);
		break;	
	case "高级奖励":
		ret = get_bonus3(who);
		break;
	case "特级奖励":
		ret = get_bonus4(who);
		break;	
	}
	if ( !ret )
		return ;
	who->set_save_2("online_rank.bonus",level);
}
//获取友好关系
string get_friend_desc(int i )
{
	string result;
	if ( i > 5000 )
		result = "君子之交";
	else if ( i > 3500 )
		result = "情同手足";
	else if ( i > 1800 )
		result = "至交好友";
	else if ( i > 800 )
		result = "海内知己";
	else if ( i > 200 )
		result = "萍水相逢";
	else 
		result = "普通朋友";	
	return result;	
}
