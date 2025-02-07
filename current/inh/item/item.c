#include <item.h>
#include <equip.h>
#include <ansi.h>

inherit DBASE_F;

private string Name;                    // ��������

private string ProductID;		// �����ߵ�����

private int PicId1;                     // �ر�����
private int PicId2;                     // ����������

private int Value;                      // �����ֵ
private int BonusValue;                 // ���¼�ֵ
private string Unit;                    // ���嵥λ
private int Level;                      // �ȼ�����

private int NoDrop;                     // ���ɶ���(����drop, give, exchange, store)(��������)
private int NoGet;                      // ����ֱ��ȡ��(����get)(��������)
private int NoGive;                     // ���ɸ���(����give, exchange, store)(��������)
private int NoSell;                     // ��������(����sell)

static int RecordMessage;			// �Ƿ��¼��Դ��������Ϣ
static int NoSave;				// �Ƿ����

/*
Value: -1  ���� sell, pawn
        0  ���� sell, pawn����������ʧ
        1  ���� pawn

�� NoDrop, NoGet, NoGive, NoSell ��־������ Value <= 1 ���� pawn
*/

private string UserID;                  // ��������
private int LockTime;                   // ������ʼ
private int LockUntil;                  // ����ʱ��

private int DropTime;                   // ����ʱ��

// ����������ʶ��
int is_item() { return 1; }

// -------------------------------------------------------------

// ��������ȡ��Ʒ����
string get_name() { return Name; }

// ������������Ʒ����
string set_name( string name ) 
{ 
        object who;
        int id;

        if( ( who = environment() ) && who->get_login_flag() > 1 )
        {
                id = getoid( this_object() );
                send_user( who, "%c%c%d%s", 0x3d, 6, id, name );
                send_user( who, "%c%d%c", 0x31, id, 0 );
        }

        return Name = name; 
}

// ����������ʶ����
int id( string arg ) 
{ 
        if( !arg || arg == "" ) return 0;
        if( arg[<1] == '#' ) return arg != sprintf( "%x#", getoid( this_object() ) ) ? 0 : 1;
        return arg != get_name() ? 0 : 1;
}

// ��������ȡ�ر�����
int get_picid_1() { return PicId1; }

// ���������õر�����
int set_picid_1( int id ) { return PicId1 = id; }

// ��������ȡ����������
int get_picid_2() { return PicId2; }

// ���������õ���������
int set_picid_2( int id ) { return PicId2 = id; }

// ��������ȡ���߼�ֵ
int get_value() { return Value; }

// ���������õ��߼�ֵ
int set_value( int value ) { return Value = value; }

// ��������ȡ���¼�ֵ
int get_bonus_value() { return BonusValue; }

// ���������ù��¼�ֵ
int set_bonus_value( int value ) { return BonusValue = value; }

// ��������ȡ���ߵ�λ
string get_unit() { return Unit; }

// ���������õ��ߵ�λ
string set_unit( string unit ) { return Unit = unit; }

// ��������ȡ�ȼ�����
int get_level() { return Level; }

// ���������õȼ�����
int set_level( int point ) { return Level = point; }

// �������жϲ��ɶ���
int get_no_drop() { return NoDrop; }

// ���������ò��ɶ���
int set_no_drop( int flag ) { return NoDrop = flag; }

// �������жϲ��ɻ�ȡ
int get_no_get() { return NoGet; }

// ���������ò��ɻ�ȡ
int set_no_get( int flag ) { return NoGet = flag; }

// �������жϲ��ɸ���
int get_no_give() { return NoGive; }

// ���������ò��ɸ���
int set_no_give( int flag ) { return NoGive = flag; }

// �������жϲ�������
int get_no_sell() { return NoSell; }

// ���������ò�������
int set_no_sell( int flag ) { return NoSell = flag; }

// ��������ȡ������
string get_product_id() { return ProductID; }

// ����������������
string set_product_id( string id ) { return ProductID = id; }


// -------------------------------------------------------------

// ��������ȡ��������
string get_user_id() { return UserID; }

// ������������������
string set_user_id( string id ) { return UserID = id; }

// ��������ȡ������ʼ
int get_lock_time() { return LockTime; }

// ����������������ʼ
int set_lock_time( int time ) { return LockTime = time; }

// ��������ȡ����ʱ��
int get_lock_until() { return LockUntil; }

// ��������������ʱ��
int set_lock_until( int time ) { return LockUntil = time; }

// �������Ƿ��������
int is_locked() 
{ 
	return LockUntil - gone_time(LockTime) ;
}

// ���������õ�������
int set_locked( int time )
{
        LockTime = time();
        return LockUntil = time;
}

// ��������ȡ����ʱ��
int get_drop_time() { return DropTime; }

// ���������ö���ʱ��
int set_drop_time( int time ) { return DropTime = time; }

// -------------------------------------------------------------

// ��������ʾ��Ʒ����
void do_look( object who )    // ���ڵ�������Ʒ
{
        object item = this_object();
        send_user( who, "%c%d%s", 0x31, getoid(item), ITEM_ITEM_D->get_look_string(who, item) );
}

// ��������ʾ��Ʒ����
void do_look_2( object who, int what, int type )
{
        object item = this_object();

        switch( type )
        {
       case 0 : // ���ڵر���Ʒ
                send_user( who, "%c%d%s", 0x32, getoid(item), ITEM_ITEM_D->get_look_string(who, item) );  break;

       case 1 : // ����С����Ʒ(���ﲻ��ʾ������)
                send_user( who, "%c%c%s", 0x33, what, ITEM_ITEM_D->get_look_string(who, item, 1) );  break;

       case 2 : // ����Ǯׯ��Ʒ
                send_user( who, "%c%c%s", 0x34, what, ITEM_ITEM_D->get_look_string(who, item) );  break;
        }
}

// -------------------------------------------------------------

// �������Ƶ�Ŀ������
int move( mixed what, int index )
{
        object who;

        if( objectp(what) ) who = what;    // Ѱ��Ŀ��
        else if( !stringp(what) ) return 0;
        else if( !( who = load_object(what) ) ) return 0;

        if( sizeof_inventory(who, 1, MAX_CARRY*4) >= MAX_CARRY*4 ) return 0;    // �ռ��ж�
        switch( index )    // �ƶ�����
        {
      default : move_item(who, index, MAX_CARRY*4);  break;
       case 0 : move_item(who, 0, 0);  break;
      case -1 : move_item(who, 1, MAX_CARRY);  break;
        }

        if( !environment() ) return 0;    // Ŀ�Ĳ�����

        return get_d( this_object() );
}

// ���������Ѱ��һ�����ʵ�λ�ý��з���
int move2( object me )
{
	object item = this_object();
	int bag, b, c, d, pos;
	if (!me->is_user()) return 0;	
	bag = me->have_bag();
        b = bag % 100;
        c = (bag / 100)%100;
        d = bag / 10000;
	if (b>0 && me->get_bag1_time()>0 && time()>me->get_bag1_time()) b = 0;
	if (c>0 && me->get_bag2_time()>0 && time()>me->get_bag2_time()) c = 0;
	if (d>0 && me->get_bag3_time()>0 && time()>me->get_bag3_time()) d = 0;
        if( me->get_reincarnation() ) b = MAX_CARRY;	
        pos = get_d(item);
        set_d(item, 0);	
        move_item(me, 1, MAX_CARRY);        
        if( get_d(item) ) 
        {
        	return get_d( item );
        }
        if (b>0 )
        {
        	move_item(me, MAX_CARRY+1, MAX_CARRY+b);
        	if( get_d(item) ) 
        	{
        		return get_d( item );
        	}
        }        
        if (c>0 )
        {
        	move_item(me, MAX_CARRY*2+1, MAX_CARRY*2+c);
        	if( get_d(item) ) 
        	{     	        		
        		return get_d( item );
        	}
        }  
        if (d>0)
        {        	
        	move_item(me, MAX_CARRY*3+1, MAX_CARRY*3+d);
        	if( get_d(item) ) 
        	{      	
        		return get_d( item );
        	}
        }
        set_d(item, pos);
        return 0;    // Ŀ�Ĳ�����
}

// �������Ƶ�Ŀ������(���� inventory.c)
int restore_move( mixed what, int index )
{
        object who;

        if( objectp(what) ) who = what;    // Ѱ��Ŀ��
        else if( !stringp(what) ) return 0;
        else if( !( who = load_object(what) ) ) return 0;

        switch( index )    // �ƶ�����
        {
      default : move_item(who, index, index);  break;
       case 0 : move_item(who, 0, 0);  break;
      case -1 : move_item(who, 1, MAX_CARRY);  break;
        }

        if( !environment() ) return 0;    // Ŀ�Ĳ�����

        return get_d( this_object() );
}

// �������Ƶ�Ŀ������(ֻ���� equip.c)
int remove_equip( object who, int index ) 
{ 
        if( index < 1 ) 
                this_object()->move2(who);
        else    move_item(who, index, MAX_CARRY * 4); 
	return get_d( this_object() );
}

// ��������ʾ�������(�Է�������)
void show_to_user( object who )
{
	object leader;
        string owner;
        int team_id;
        string id;
        object item = this_object();
        team_id = item->get("team_id");
        if ( team_id )
        {
        	if ( team_id == who->get_team_id() )
        		send_user( who, "%c%d%w%w%w%c%s", 0x2e, getoid(item), get_x(item), get_y(item), get_picid_1(), item->get_item_color(), get_name() );	
        	return ;	
        }
        id = item->get_user_id();
        if( !id || id == who->get_id() ) send_user( who, "%c%d%w%w%w%c%s", 0x2e, getoid(item), get_x(item), get_y(item), get_picid_1(), item->get_item_color(), get_name() );
}

// ��������ʾ����ҿ�(�½��볡��)
void show_to_scene( object *user, int x, int y )
{
	object leader;
	string owner;
        int team_id, size, i;
        object item = this_object();
        object who;
        string id;
        
        team_id = item->get("team_id");
	user -= ({ 0 });
        if ( team_id )
        {        
                size = sizeof(user);        
                for (i=0;i<size;i++)
                {
                        if ( objectp(who=user[i]) && team_id == who->get_team_id() )
				send_user( who, "%c%d%w%w%w%c%s", 0x2e, getoid(item), get_x(item), get_y(item), get_picid_1(), item->get_item_color(), get_name() );
                }
                return ;
        }
        
        id = item->get_user_id();
        if (!id)
                send_user( user, "%c%d%w%w%w%c%s", 0x2e, getoid(item), x, y, get_picid_1(), item->get_item_color(), get_name() );
        else
        {        
                size = sizeof(user);        
                for (i=0;i<size;i++)
                {
                        if ( objectp(who=user[i]) && id == who->get_id() )
                        {
                                send_user( who, "%c%d%w%w%w%c%s", 0x2e, getoid(item), get_x(item), get_y(item), get_picid_1(), item->get_item_color(), get_name() );
                                break;
                        }                                
                }
                        
        }
}

// ���������볡������
void add_to_scene( int z, int x, int y )
{
        object item, *user;
        object obj;	
        item = this_object();
        set_z(item, z);  set_x(item, x);  set_y(item, y);
        set_block(z, x, y, ITEM_BLOCK);
        move_object(item, z, x, y, ITEM_TYPE);
        show_to_scene( get_scene_object_2(item, USER_TYPE), x, y );
        set_drop_time( time() );
        if (item->is_record() || item->is_cash() )
        {
        	obj = previous_object();
        	if (obj)
        	{
        		if (obj->is_npc())
        		{
        			item->set("from", sprintf("@%s", obj->get_name()));
        		}
        		else
        			item->set("from", sprintf("���� %s", get_file_name(obj)));
        	}
        }
}

// ������ɾ������ҿ�(�Է��볡��)
void remove_to_user( object who )
{
        send_user( who, "%c%d", 0x2f, getoid( this_object() ) );
}

// �������ӳ������Ƴ�
void remove_from_scene()
{
        object obj = this_object();
        remove_block( get_z(obj), get_x(obj), get_y(obj), ITEM_BLOCK );
        send_user( get_scene_object_2(obj, USER_TYPE), "%c%d", 0x2f, getoid(obj) );
}

// �����������������
int add_to_user( int index )
{
        object who, item = this_object(), obj, *all;
        int type, locate, level, color, itemid, total, i, size;
        string result;
        if( !( ( who = environment() ) || ( who = item->get_owner() ) ) || !userp(who) ) return 0;
        type = item->get_item_type_2();
        locate = item->get_equip_type();
        if (locate>100) locate -= 100;
        if (item->get_level()>0) level = item->get_level();
        else level = item->get("level");
        color = item->get_item_color();
        send_user( who, "%c%d%c%w%w%c%c%c%c%s", 0x2b, getoid(item), index, 
                item->get_picid_2(), item->get_amount(), type,
                color, level, locate, get_name() );
/*                
        send_user( who, "%c%d%c%w%w%c%c%c%s", 0x2b, getoid(item), index, 
                item->get_picid_2(), item->get_amount(), type,
                item->get_item_color(), item->get_level(), get_name() );
*/        
        if (item->is_record() && item->get("from")==0 && who->get_login_flag()==3 && !get_user_id())
        {
        	// ����Ψһ��ź�ʧЧʱ��
        	itemid = "/sys/sys/id"->add_max_itemid(1);
        	set_user_id( sprintf("#%d#", itemid) );        	
        	log_file("itemid.dat", sprintf("%s %d %s %s\n", short_time(), itemid, item->get_name(), "/sys/item/item"->get_pawn_save_string(item) ));
        	obj = previous_object();      
        	all = previous_object(-1);     
        	all -= ({ item, 0 });
        	size = sizeof(all);    	
        	for (i=size-1;i>=0;i--)
        	{
			if (all[i]->is_npc())
			{				
				obj = all[i];
				break;
			}        		
        	}
        	result = ""; 	
        	total = item->get_amount();
        	if (total==0) total = 1;
        	if (obj && obj->is_npc())
        	{
        		item->set("from", sprintf("npc %s", obj->get_name()));
        		result = sprintf("��� @%s %s,%d,%s,%s %s %s %d %s %d_%d_%d", obj->get_name(), who->get_name(), who->get_number(), get_ip_name(who), who->get_id(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), total, item->get_user_id(), get_z(who), get_x(who), get_y(who) );
        	}
        	else        	
        	{
        		if (obj)
        		{
        			item->set("from", sprintf("���� %s", get_file_name(obj)));
        			result = sprintf("��� @%s %s,%d,%s,%s %s %s %d %s %d_%d_%d", get_file_name(obj), who->get_name(), who->get_number(), get_ip_name(who), who->get_id(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), total, item->get_user_id(), get_z(who), get_x(who), get_y(who) );
        		}
        	}
        	"/sys/user/cmd"->log_item(result);
        }
        if (item->is_equip() && item->get_equip_type()!=FAMILY_TYPE)
        {
        	if (item->get_level()>=30 && item->get_hide()) "/quest/help"->send_help_tips(who, 7);
        	if (item->get_bind()) "/quest/help"->send_help_tips(who, 24);
        	if (item->get_item_color()>0) "/quest/help"->send_help_tips(who, 30);
        }
        else
        if (type>=ITEM_TYPE_2_ADD_HP && type <= ITEM_TYPE_2_EVER_EXTRA) 
        {
        	"/quest/help"->send_help_tips(who, 9);
        	"/quest/help"->send_help_tips(who, 11);
        }
        else
        if (type>=ITEM_TYPE_2_CON_HP && type <= ITEM_TYPE_2_CON_ALL) 
        {
        	"/quest/help"->send_help_tips(who, 10);
        	"/quest/help"->send_help_tips(who, 11);
        }
        else
        if (item->is_task_item())
        {
        	"/quest/help"->send_help_tips( who, 17 );
        }     
        else   
        if (item->get_item_type()==ITEM_TYPE_DIAMOND_3) "/quest/help"->send_help_tips( who, 31 );
//        if( !get_user_id() ) set_user_id( who->get_id() );    // ��������
        return 1;
}

// �������������ȡ��
int remove_from_user()
{
        object who;

        if( ( who = environment() ) && userp(who) )
        {
                send_user( who, "%c%d", 0x2d, getoid( this_object() ) );
                return 1;
        }
        else    return 0;
}

// �ж���Ʒ�Ƿ�������
int if_in_user(object who)
{
	object me;
	if( me = environment() )
	{
		if (me==who) return 1;
	}
	return 0;
}

// -------------------------------------------------------------

// ��������λ����
void reset()
{
        if( gone_time( get_drop_time() ) > 600 )    // ʮ����ˢ��
        {
                remove_from_scene();
                destruct( this_object() );
        }
}

// �Ƿ���Ҫ��¼
int is_record( )    
{
        object item = this_object();
        if (RecordMessage>0||item->get_item_value()||(item->get_item_color()!=0 && item->get_item_color()!=4 )) return 1;
        return 0;
}

int set_record (int flag)
{
	RecordMessage = flag;
}

string get_item_make_desc()
{
	object item = this_object();
	string make, color;
	int size;
	if (!clonep(item)) return "";
	make = item->get("make");
	size = strlen(make);
	if (size==0) return "";
	if (size<=5) color = NOR;
	else
	if (size<=8) color = HIC;
	else
	if (size==9) color = HIY;
	else
	color = HIM;
	return sprintf(" %s+%d%s", color, size, NOR);
}

// �������жϲ��ɴ���
int get_no_save() { return NoSave; }

// ���������ò��ɴ���
int set_no_save( int flag ) { return NoSave = flag; }