
#include <ansi.h>
#include <item.h>

#define MONSTER         "/npc/task/8001"
#define ZOMBIE          "/npc/task/8002"

inherit ITEM;
inherit USABLE;

private int Z, X, Y;

int get_item_value() {return 1 ;}
int get_item_value_2() {return 1 ;}
int get_item_number() {return 10001072 ;}
int get_item_color() { return 1; }
// �������ر�ͼ
// int is_treasure() { return 1; }

// �������ر�ͼ
int get_item_type() { return ITEM_TYPE_TREASURE; }

// ��������ȡ������
int get_map_z() { return Z; }

// ���������ã�����
int set_map_z( int z ) { return Z = z; }

// ��������ȡ������
int get_map_x() { return X; }

// ���������ã�����
int set_map_x( int x ) { return X = x; }

// ��������ȡ������
int get_map_y() { return Y; }

// ���������ã�����
int set_map_y( int y ) { return Y = y; }

// ���������촦��
void create()
{
        set_name( "�ر�ͼ" );
        set_picid_1(8000);
        set_picid_2(8000);
        set_unit( "��" );
        set_value(100);
}

// ��������ȡ����
string get_desc() 
{ 
        object map;
        int p;
	if (!clonep()) return "ͨ���������ҵ�����"; 
        if( !( map = get_map_object(Z) ) )
        {
                if( p = XY_D->get_city_point(-1, IS_ITEM_BLOCK) )
                {
                        set_map_z( p / 1000000 );
                        set_map_x( ( p % 1000000 ) / 1000 );
                        set_map_y( p % 1000 );
                }
        }
        return "ͨ���������ҵ�����"; 
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me, object item )
{
        object map, *monster, npc;
        string name, file, result = "";
        int level, level2, pic, gold, p, i, size;
        int z0, x0, y0, z, x, y;

        if(     get_z(me) != item->get_map_z()
        ||      abs( get_x(me) - item->get_map_x() ) > 2
        ||      abs( get_y(me) - item->get_map_y() ) > 2 )
        {
                send_user(me, "%c%s", '!', "���ڱ���λ�ò��ԡ�");
                return 0;
        }
	if ( me->get_online_rate() == 50 )
	{
		send_user(me,"%c%s",'!',"ƣ����Ϸʱ���ֹʹ�òر�ͼ��");
		return 0;	
	}
	else if ( me->get_online_rate() == 0 )
	{
		send_user(me,"%c%s",'!',"��������Ϸʱ���ֹʹ�òر�ͼ��");
		return 0;	
	}
        name = item->get_name();
	item->remove_from_user();    // �ճ�λ��
	destruct(item);
	if (MAIN_D->get_host_type()==1||MAIN_D->get_host_type()==1000)
	{
		if (random100()<2 )
		{
	                item = new( "/item/sell/0021" );
	                if( p = item->move(me, -1) ) 
	                {
	                        item->add_to_user(p);
	                        write_user(me, ECHO "������%s���������ҵ� %s��", name, item->get_name() );
	                }
	                else    destruct(item);    		
		}
	}
	// �õ�����ľ����Ǳ�ܽ���
	p = 500 + random(me->get_level()*100);
	me->add_exp(p);
	me->add_potential(p/500+1);
        p = random(100);
        if( p < 7 )    // ��Ǯ
        {
                gold = me->get_level() * 20 + random(501);
                me->add_cash(gold);  me->add_gold_log("task", gold);
		me->log_money("�ر�ͼ", gold);                
                "/sys/sys/count"->add_income("item8000", gold);
                write_user(me, ECHO "������%s���������õ� %d ��", name, gold );
        }
        else if( p < 9 )    // ��Ԫ��
        {
                item = new( "item/44/4488" );
                p = "quest/pet"->get_drop_skill1();
		if ( p )
			item->set("special",sprintf("%d",p));
                if( p = item->move(me, -1) ) 
                {
                        item->add_to_user(p);
                        write_user(me, ECHO "������%s���������ҵ� %s��", name, item->get_name() );
                }
                else    destruct(item);        	
        }
        else if( p < 10 )    // ����Һ
        {
                item = new( "item/44/4404" );
                if( p = item->move(me, -1) ) 
                {
                        item->add_to_user(p);
                        write_user(me, ECHO "������%s���������ҵ� %s��", name, item->get_name() );
                }
                else    destruct(item);        	
        }
        else if( p < 30 )    // ����
        {
                switch( level = 35 + random(8) * 10 )    // 35��45��55��65��75��85��95��105�������
                {
              default : result = "��ͥˮ��";  pic = 8010;  level2 = 6;  break;
              case 45 : result = "ɽ������";  pic = 0251;  level2 = 2;  break;
              case 55 : result = "̫��ɽ��";  pic = 8011;  level2 = 4;  break;
              case 65 : result = "��ԭ���";  pic = 0252;  level2 = 8;  break;
              case 75 : result = "ɽ������";  pic = 8012;  level2 = 1;  break;
              case 85 : result = "��������";  pic = 8012;  level2 = 3;  break;
              case 95 : result = "����ɽ��";  pic = 8011;  level2 = 7;  break;
             case 105 : result = "Į������";  pic = 8013;  level2 = 5;  break;
                }

                size = 5;
                for( i = 0; i < size; i ++ )
                {
                        if( !( p = XY_D->get_city_point(level2, IS_CHAR_BLOCK) ) ) continue;

                        z = p / 1000000;  x = ( p % 1000000 ) / 1000;  y = p % 1000;

                        npc = new( MONSTER );

                        if( !objectp( map = get_map_object(z) ) || !map->is_scene() )
                        {
                                destruct(npc);  continue;
                        }
                        monster = map->get("monster");
                        if( arrayp(monster) )
                        {
                                monster -= ({ 0 });
                                if( sizeof(monster) >= 100 )    // ͬ�������ܳ�����ֻ
                                {
                                        destruct(npc);  continue;
                                }
                        }
                        else    monster = ({ });

                        npc->set_name(result);
                        npc->set_char_picid(pic);
                        NPC_ENERGY_D->init_level(npc, level);
                        npc->add_max_hp(npc->get_max_hp()*21);
                        npc->add_dp( level * 15 / 10 );
                        npc->add_pp( level * 8 / 10 );
                        npc->add_ap( level * 2 );
                        npc->add_to_scene(z, x, y, 3);
		        npc->set_walk_speed(4);
		        npc->set_attack_speed(15);                        
                        npc->set( "task", me->get_number() );

                        map->add_reset(npc);    // ���븴λ�б�

                        monster += ({ npc });  map->set("monster", monster);
                }
                if( map )
                {
                        result = sprintf( "%sϴ����%s�ڳ��ı��أ������Ӵܵ�"HIR"%s��"NOR"��", result, me->get_name(), map->get_name() );
                        USER_D->user_channel(result);
                }
        }
        else if( p < 38 )    // ��ʬ
        {
                z0 = get_z(me);  x0 = get_x(me);  y0 = get_y(me);

                for( i = 0; i < 2; i ++ )
                {
                        npc = new( ZOMBIE );
                        if( !( p = get_valid_xy(z0, x0, y0, IS_CHAR_BLOCK) ) )
                        {
                                destruct(npc);  continue;
                        }
                        x = p / 1000;  y = p % 1000;

                        level = me->get_level() - random(6);
                        if( level < 0 ) level = 0;
                        NPC_ENERGY_D->init_level(npc, level);
                        npc->add_max_hp(750);
                        npc->add_dp( level * 75 / 100 );
                        npc->add_pp( level * 180 / 100 );
			npc->add_ap( level * 150 / 100 );
			
                        npc->add_to_scene( z0, x, y, get_front_xy(x, y, x0, y0) );
                        me->to_front_xy(x, y);

                        npc->set( "task", me );
                        npc->start_fight(me);    // ��������
                }
                write_user( me, ECHO "���ڱ��������ػ����صĽ�ʬ��" );
        }
        else if ( p < 39 )	//2����ʯ
        {
                if( load_object( file = STONE_FILE->get_diamond_file() ) )
                {
                        item = new( file );
                        item->set_level(2);
                        if( p = item->move(me, -1) ) 
                        {
                                item->add_to_user(p);
                                write_user(me, ECHO "������%s���������ҵ� %s��", name, item->get_name() );
                        }
                        else    destruct(item);
                }
        }
        else if( p < 45 )    // ��ɫҩƷ
        {
                switch( random(7) )
                {
               case 0 : item = new( "/item/91/9160" );  break;
               case 1 : item = new( "/item/91/9161" );  break;
               case 2 : item = new( "/item/91/9162" );  break;
               case 3 : item = new( "/item/91/9163" );  break;
               case 4 : item = new( "/item/91/9164" );  break;
               case 5 : item = new( "/item/91/9165" );  break;
               case 6 : item = new( "/item/91/9167" );  break;
                }

                if( p = item->move(me, -1) ) 
                {
                        item->add_to_user(p);
                        write_user(me, ECHO "������%s���������ҵ� %s��", name, item->get_name() );
                }
                else    destruct(item);
        }
        else if( p < 75 )    //�õ���ͨװ������
        {
                if( random(2) ) 
                        file = ARMOR_FILE->get_armor_file_2( me->get_level() );
                else    file = WEAPON_FILE->get_weapon_file_2( me->get_level() );
                if( load_object(file) )
                {
                        item = new( file );
                        if( p = item->move(me, -1) ) 
                        {
                                item->add_to_user(p);
                                write_user(me, ECHO "������%s���������ҵ� %s��", name, item->get_name() );
                        }
                        else    destruct(item);
                }
        }
        else if( p < 76 )    // �����Ը��ӵ�װ��
        {
               if( random(2) ) 
                        file = ARMOR_FILE->get_armor_file_2( me->get_level() );
                else    file = WEAPON_FILE->get_weapon_file_2( me->get_level() );
                if( load_object(file) )
                {
                        item = new( file );
			ITEM_EQUIP_D->init_equip_prop_1(item);
                        if( p = item->move(me, -1) ) 
                        {
                                item->add_to_user(p);
                                write_user(me, ECHO "������%s���������ҵ� %s��", name, item->get_name() );
                        }
                        else    destruct(item);
                }
        }
        else if( p < 88 )    // ������ϵĵͼ��м��Ʒ
        {
                if( load_object( file = "sys/item/product"->get_random_mid_product() ) )
                {
                        item = new( file );
                        if( p = item->move(me, -1) ) 
                        {
                                item->add_to_user(p);
                                write_user(me, ECHO "������%s���������ҵ� %s��", name, item->get_name() );
                        }
                        else    destruct(item);
                }
        }
        else if( p < 89 )    // ���Ʋر�ͼ
        {
                switch( random(4) )
                {
               case 0 : item = new( "/item/std/8001" );  break;
               case 1 : item = new( "/item/std/8002" );  break;
               case 2 : item = new( "/item/std/8003" );  break;
               case 3 : item = new( "/item/std/8004" );  break;
                }
                if( p = item->move(me, -1) ) 
                {
                        item->add_to_user(p);
                        write_user(me, ECHO "������%s���������ҵ� %s��", name, item->get_name() );
                }
                else    destruct(item);
        }
        else if ( p < 90 )	//���� ��Ϊ��Ǯ
	{
                gold = me->get_level() * 20 + random(501);
                me->add_cash(gold);  me->add_gold_log("task", gold);
		me->log_money("�ر�ͼ", gold);                
                "/sys/sys/count"->add_income("item8000", gold);
                write_user(me, ECHO "������%s���������õ� %d ��", name, gold );
        }        	
//        {
//
//        	p = random(10000);
//        	if ( p < 3500 )
//        		item = new( "/item/std/9501" );	
//        	else if ( p < 4150 )
//        		item = new( "/item/std/9511" );	
//        	else if ( p < 4250 )
//        		item = new( "/item/std/9521" );	
//        	else if ( p < 5250 )
//        		item = new( "/item/std/9531" );	
//        	else if ( p < 6550 )
//        		item = new( "/item/std/9541" );	
//        	else if ( p < 7050 )
//        		item = new( "/item/std/9551" );	
//        	else if ( p < 8350 )
//        		item = new( "/item/std/9561" );	
//        	else if ( p < 9600 )
//        		item = new( "/item/std/9571" );	
//        	else 
//        		item = new( "/item/std/9581" );	
//		if( p = item->move(me, -1) ) 
//                {
//                        item->add_to_user(p);
//                        write_user(me, ECHO "������%s���������ҵ� %s��", name, item->get_name() );
//                }
//                else    destruct(item);
//
//        }
        else	//ͬ�ڱ��ߵȼ��ε����������䷽һ��
        {
                gold = me->get_level() * 20 + random(501);
                me->add_cash(gold);  me->add_gold_log("task", gold);
		me->log_money("�ر�ͼ", gold);                
                "/sys/sys/count"->add_income("item8000", gold);
                write_user(me, ECHO "������%s���������õ� %d ��", name, gold );
        }
//        {��ʱ�����Ÿ�Ϊ��Ǯ
//        	level2 = me->get_level()/10*10;
//        	if ( level2 > 70 ) level2 = 70;
//                if( load_object( file = "/quest/product2"->get_random_level_product(level2,level2) ) )
//                {
//                        item = new( file );
//                        if( p = item->move(me, -1) ) 
//                        {
//                                item->add_to_user(p);
//                                write_user(me, ECHO "������%s���������ҵ� %s��", name, item->get_name() );
//                        }
//                        else    destruct(item);
//                }
//        }

        return 0;
}
