
// �Զ����ɣ�/make/item/make89b

inherit ITEM;

// ��������ʯʶ��
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
int is_diamond() { return 1; }

// ��������Ҫȷ������
int confirm_sell_item() { return 1; }

// ��������ʯ����
string get_diamond_type() { return "-1-"; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8972);
        set_picid_2(8972);
        set_unit("��");
        set_value(50000);
}

// ��������ȡ����
string get_desc() 
{ 
        return "��װ���ϳɲ��ϣݽ���װ������"; 
}
