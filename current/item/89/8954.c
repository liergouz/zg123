
// �Զ����ɣ�/make/item/make89b

inherit ITEM;

// ��������ʯʶ��
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
int is_diamond() { return 1; }

// ��������Ҫȷ������
int confirm_sell_item() { return 1; }

// ��������ʯ����
string get_diamond_type() { return "mp%"; }

// ���������촦��
void create()
{
        set_name("������쾧ʯ");
        set_picid_1(8954);
        set_picid_2(8954);
        set_unit("��");
        set_value(50000);
}

// ��������ȡ����
string get_desc() 
{ 
        return "��װ���ϳɲ��ϣ����ӷ����ٷֱ�"; 
}
