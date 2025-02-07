
#include <item.h>
#include <equip.h>

private int HaveBag;                    // ӵ�а���
private int Bag1Time;			// ��һ�������Ľ���ʱ��
private int Bag2Time;			// �ڶ��������Ľ���ʱ��
private int Bag3Time;			// �����������Ľ���ʱ��

private string *Inventory;              // ��������

// -------------------------------------------------------------

// �������Ƿ�ӵ�а���
int have_bag() { return HaveBag; }

// ����������ӵ�а���
int set_have_bag( int flag )
{ 
/*	
        if( HaveBag != flag ) 
        {
                HaveBag = flag;    // ��ǰ����
                USER_INVENTORY_D->send_max_carry_flag( this_object() );
        }
*/        
        return HaveBag = flag; 
}

int get_bag1_time() {return Bag1Time;}
int get_bag2_time() {return Bag2Time;}
int get_bag3_time() {return Bag3Time;}

int set_bag1_time( int flag ) { return Bag1Time = flag;}
int set_bag2_time( int flag ) { return Bag2Time = flag;}
int set_bag3_time( int flag ) { return Bag3Time = flag;}

// -------------------------------------------------------------

// ��������ȡ��������
string *get_inventory() { return copy(Inventory); }

// �����������������
void init_inventory() { Inventory = ({ }); }

// �����������������
void save_inventory()
{
        object me, *inv, item;
        string id, file;
        int amount, index, point, locktime, lockutil;
        int i, size;

        Inventory = ({ });

        me = this_object();  inv = me->get_all_equip() + all_inventory(me, 0, 0);

        for( i = 0, size = sizeof(inv); i < size; i ++ ) if( item = inv[i] )
        {
        	if ( item->get_no_save() )	//�����棬���߾���ʧ
        		continue;
                file = get_file_name(item);
                amount = item->get_amount();
                index = get_d(item);

                if( !stringp( id = item->get_user_id() ) ) id = "-";
                locktime = item->get_lock_time();
                lockutil = item->get_lock_until();

                switch( item->get_item_type() )
                {
         case ITEM_TYPE_EQUIP : Inventory += ({ sprintf( "%s;%d;%d;%d;%d;%s;[%s]%d,%d", 
                                        file, amount, index, item->get_lasting(), item->get_max_lasting(), ITEM_EQUIP_D->get_save_prop_string(item), id, locktime, lockutil ) });
                                break;

      case ITEM_TYPE_TALISMAN : switch( item->get_talisman_type() )
                                {
                              default : point = 0;  break;
                               case 2 : point = item->get_hp();  break;    // ���������
                               case 9 : point = item->get_heart_sec();  break;    // �л��
                                }
                                Inventory += ({ sprintf( "%s;%d;%d;%d;%d;%d;[%s]%d,%d", 
                                        file, amount, index, item->get_lasting(), item->get_max_lasting(), point, id, locktime, lockutil ) });
                                break;

      case ITEM_TYPE_POISON_2 : Inventory += ({ sprintf( "%s;%d;%d;%d;[%s]%d,%d", 
                                        file, amount, index, item->get_poison(), id, locktime, lockutil ) });
                                break;

          case ITEM_TYPE_GOOD : Inventory += ({ sprintf( "%s;%d;%d;%d;[%s]%d,%d", 
                                        file, amount, index, item->get_buyin(), id, locktime, lockutil ) });
                                break;
       case ITEM_TYPE_CHEQUE2 :
        case ITEM_TYPE_CHEQUE : Inventory += ({ sprintf( "%s;%d;%d;%d;%d;[%s]%d,%d", 
                                        file, amount, index, item->get_orgin_money(), item->get_money(), id, locktime, lockutil ) });
                                break;

      case ITEM_TYPE_TREASURE : Inventory += ({ sprintf( "%s;%d;%d;%d;%d;%d;[%s]%d,%d", 
                                        file, amount, index, item->get_map_z(), item->get_map_x(), item->get_map_y(), id, locktime, lockutil ) });
                                break;

     case ITEM_TYPE_DIAMOND_2 : Inventory += ({ sprintf( "%s;%d;%d;%d;[%s]%d,%d", 
                                        file, amount, index, item->get_item_level(), id, locktime, lockutil ) });
                                break;

     case ITEM_TYPE_POTENTIAL : Inventory += ({ sprintf( "%s;%d;%d;%d;[%s]%d,%d", 
                                        file, amount, index, item->get_potential(), id, locktime, lockutil ) });
                                break;
     case ITEM_TYPE_SPECIAL :
     				Inventory += ({ sprintf( "%s;%d;%d;%s;[%s]%d,%d", file, amount, index,item->get("special"), id, locktime, lockutil ) });
     				break;
    case ITEM_TYPE_DIAMOND_3 :     	
    				Inventory += ({ sprintf( "%s;%d;%d;[%s]%d,%d", file, item->get_level(), index, id, locktime, lockutil ) });
                                break;			
                      default : Inventory += ({ sprintf( "%s;%d;%d;[%s]%d,%d", file, amount, index, id, locktime, lockutil ) });
                                break;
                }
        }
}

// ��������ȡ��������
void restore_inventory()
{
        object me, item;
        string id, file, prop,special;
        int amount, index, use, maxuse, locktime, lockutil;
        int point, point2, point3;
        int i, size;

        me = this_object();
        if( arrayp(Inventory) && sizeof(Inventory) ) for( i = 0, size = sizeof(Inventory); i < size; i ++ )
        {
                sscanf( Inventory[i], "%s;%*s", file );
                if( !load_object(file) ) continue;

                switch( file->get_item_type() )
                {
         case ITEM_TYPE_EQUIP : if( sscanf( Inventory[i], "%s;%d;%d;%d;%d;%s;[%s]%d,%d", file, amount, index, use, maxuse, prop, id, locktime, lockutil ) != 9 ) continue;

                                item = new(file);
                                if( amount ) item->set_amount(amount);
                                item->set_max_lasting(maxuse);  item->set_lasting(use);

                                ITEM_EQUIP_D->set_prop_baseon_string(item, prop);

                                break;

      case ITEM_TYPE_TALISMAN : 
      				if ( file->get_name() == "ͬ����" && !me->get_save_2("marry"))
      					continue;
      				if( sscanf( Inventory[i], "%s;%d;%d;%d;%d;%d;[%s]%d,%d", file, amount, index, use, maxuse, point, id, locktime, lockutil ) != 9 ) continue;

                                item = new(file);
                                if( amount ) item->set_amount(amount);
                                item->set_max_lasting(maxuse);  item->set_lasting(use);

                                switch( item->get_talisman_type() )
                                {
                              default : break;
                               case 2 : item->set_hp(point);  break;    // ���������
                               case 9 : item->set_heart_sec(point);  break;    // �л��
                                }

                                break;

      case ITEM_TYPE_POISON_2 : if( sscanf( Inventory[i], "%s;%d;%d;%d;[%s]%d,%d", file, amount, index, point, id, locktime, lockutil ) != 7 ) continue;

                                item = new(file);
                                if( amount ) item->set_amount(amount);
                                item->set_poison(point);

                                break;

          case ITEM_TYPE_GOOD : if( sscanf( Inventory[i], "%s;%d;%d;%d;[%s]%d,%d", file, amount, index, point, id, locktime, lockutil ) != 7 ) continue;

                                item = new(file);
                                if( amount ) item->set_amount(amount);
                                item->set_buyin(point);

                                break;
        
        case ITEM_TYPE_CHEQUE2:
        case ITEM_TYPE_CHEQUE : if( sscanf( Inventory[i], "%s;%d;%d;%d;%d;[%s]%d,%d", file, amount, index, point, point2, id, locktime, lockutil ) != 8 ) continue;

                                item = new(file);
                                if( amount ) item->set_amount(amount);
                                item->set_orgin_money(point);  item->set_money(point2);

                                break;

      case ITEM_TYPE_TREASURE : if( sscanf( Inventory[i], "%s;%d;%d;%d;%d;%d;[%s]%d,%d", file, amount, index, point, point2, point3, id, locktime, lockutil ) != 9 ) continue;

                                item = new(file);
                                if( amount ) item->set_amount(amount);
                                item->set_map_z(point);  item->set_map_x(point2);  item->set_map_y(point3);

                                break;

     case ITEM_TYPE_DIAMOND_2 : if( sscanf( Inventory[i], "%s;%d;%d;%d;[%s]%d,%d", file, amount, index, point, id, locktime, lockutil ) != 7 )
                                {
                                        point = 0;
                                if( sscanf( Inventory[i], "%s;%d;%d;[%s]%d,%d", file, amount, index, id, locktime, lockutil ) != 6 )
                                {
                                        if( sscanf( Inventory[i], "%s;%d;%d;%d", file, amount, index, point ) != 4 ) continue;
                                        id = "-";  locktime = 0;  lockutil = 0;
                                }
                                }
                                item = new(file);
                                if( amount ) item->set_amount(amount);
                                item->set_item_level(point);

                                break;

     case ITEM_TYPE_POTENTIAL : if( sscanf( Inventory[i], "%s;%d;%d;%d;[%s]%d,%d", file, amount, index, point, id, locktime, lockutil ) != 7 )
                                {
                                        point = 0;
                                if( sscanf( Inventory[i], "%s;%d;%d;[%s]%d,%d", file, amount, index, id, locktime, lockutil ) != 6 )
                                {
                                        if( sscanf( Inventory[i], "%s;%d;%d;%d", file, amount, index, point ) != 4 ) continue;
                                        id = "-";  locktime = 0;  lockutil = 0;
                                }
                                }
                                item = new(file);
                                if( amount ) item->set_amount(amount);
                                item->set_potential(point);

                                break;
	case ITEM_TYPE_SPECIAL : if( sscanf( Inventory[i], "%s;%d;%d;%s;[%s]%d,%d", file, amount, index, special,id, locktime, lockutil ) != 7 ) continue;

                                item = new(file);
                                if( amount ) item->set_amount(amount);
				item->set("special",special);
                                break;
	case ITEM_TYPE_DIAMOND_3 :   
				if( sscanf( Inventory[i], "%s;%d;%d;[%s]%d,%d", file, amount, index, id, locktime, lockutil ) != 6 ) continue;

                                item = new(file);
                                if( amount ) item->set_level(amount);

                                break;                            
                      default : if( sscanf( Inventory[i], "%s;%d;%d;[%s]%d,%d", file, amount, index, id, locktime, lockutil ) != 6 ) continue;

                                item = new(file);
                                if( amount ) item->set_amount(amount);

                                break;
                }
/*                
                if( gone_time(locktime) > lockutil )    // �����Ƿ�����
                {
                        locktime = 0;  lockutil = 0;
                }
*/                
                item->set_user_id(id);  item->set_lock_time(locktime);  item->set_lock_until(lockutil);
                if( HEAD_TYPE <= index && index <= BACK_TYPE )
                {
                        if( me->restore_equip(item) ) continue;
                        else index = -1;
                }
                else    if( number_present(me, index, 0, 0) ) index = -1;    // �ݴ���

                index = item->restore_move(me, index);
                item->add_to_user(index);
        }

        USER_INVENTORY_D->send_lasting_tips(me);

        // Inventory = ({ });
}

// ����������֮ǰ����
void before_destruct()
{
        object *inv;
        int i, size;

        inv = this_object()->get_all_equip() + all_inventory( this_object(), 0, 0 );
        for( i = 0, size = sizeof(inv); i < size; i ++ ) if( inv[i] ) destruct( inv[i] );
}
