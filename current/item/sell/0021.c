#include <ansi.h>
inherit ITEM;
// 函数：构造处理
void create()
{
        set_name("财神符");
        set_picid_1(3858);
        set_picid_2(3858);
        set_value(50);

}
int is_usable() {return 1;}
// 函数：获取描述
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc()
{
        return "恭喜發財！恭喜發財！恭喜大家發財～～”（滑鼠右鍵點擊使用）";
}
// 函数：复位处理
void reset()
{
        if( gone_time( get_drop_time() ) >= 1800 )    // 30分钟刷新
        {
                remove_from_scene();
                destruct( this_object() );
        }
}

int get_use_effect( object me )
{
	__FILE__->get_use_effect_callout(me,this_object());
	return 0;
}

int get_use_effect_callout( object who,object item)
{
	int p, price;
	string file;
	if (MAIN_D->get_host_type()==1||MAIN_D->get_host_type()==1000)
	{
		p = random100();
		if (p<60) price = 100;
		else
		if (p<80) price = 400;
		else
		if (p<90) price = 600;
		else
		if (p<95) price = 800;
		else
		if (p<98) price = 1600;
		else price = 2000;
		price /= 10;
		who->add_save("testbonus", price);	
		send_user(who,"%c%s",'!',sprintf("您的角色获得%d元宝。", price));	
		item->remove_from_user();
		destruct(item);		
		return 0;
	}
	if( !who->get_pay_money_buy_item() )
	{
		p = random100();
		if (p<20) price = 50;
		else
		if (p<60) price = 100;
		else
		if (p<80) price = 400;
		else
		if (p<90) price = 600;
		else
		if (p<95) price = 800;
		else
		if (p<98) price = 1600;
		else price = 2000;
		who->set_pay_money_buy_item(1);
		who->set_pay_type(3);
		who->set_buy_item_cmd_string(" ");
log_file("deposit.dat", sprintf("%s %s(%d) 使用财神符充值%d\n", short_time(), who->get_id(), who->get_number(), price));
               	db_user_pay( who, sprintf( "%s:80\n"
			"GET /xq2/deposit.php?id=%s&time=%d&region=%d&host=%d&type=%d&point=%d&ip=%s\r\n", MAIN_D->get_php_ip(),
       	                rawurlencode( who->get_id() ), time(), MAIN_D->get_region(), MAIN_D->get_host(), 1, price, get_ip_name(who) ) );    // 扣点！
//log_file("php.dat", sprintf( "%s:80\n"
//			"GET /xq2/deposit.php?id=%s&time=%d&region=%d&host=%d&type=%d&point=%d&ip=%s\r\n", MAIN_D->get_php_ip(),
  //     	                rawurlencode( who->get_id() ), time(), MAIN_D->get_region(), MAIN_D->get_host(), 1, price, get_ip_name(who) ) );
		send_user(who,"%c%s",'!', sprintf("您使用财神符，充值%d个元宝", price));
		write_user( who, ECHO "您使用财神符，充值%d个元宝", price);
	}
	else
	{
		send_user(who,"%c%s",'!',"现在无法充值。");
		return 0;
	}
	item->remove_from_user();
	destruct(item);

	//金色装备
	if ( random(1000) >= 5 )
		return 0;
	p = who->get_level();
	p = p<50?50:p;
	if( random(2) )
	        file = ARMOR_FILE->get_armor_file_2( p );
	else    file = WEAPON_FILE->get_weapon_file_2( p );
	if( load_object(file) )
	{
	        item = new( file );
		ITEM_EQUIP_D->init_equip_prop_3(item);
	        if( p = item->move(who, -1) )
	        {
	                item->add_to_user(p);
	                send_user(who,"%c%s",'!',"恭喜你得到"HIR+file->get_name());
	        }
	        else    destruct(item);
	}

	return 0;
}


