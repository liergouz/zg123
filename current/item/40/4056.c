
// �Զ����ɣ�/make/item/make30

inherit ITEM;
    inherit COMBINED;

// ��������ȡװ����ɫ����ɫ
int get_item_color() { return 0; }

// ��������������
//  int get_max_combined() { return 30; }

// ���������촦��
void create()
{
        set_name("ǹͷ");
        set_picid_1(4056);
        set_picid_2(4056);
        set_value(338);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "һ�ַ���������Ʒ��������Ʒ��"; 
}
