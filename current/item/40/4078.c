
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
        set_name("������");
        set_picid_1(4078);
        set_picid_2(4078);
        set_value(540);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "����װ���Լ���һ��ͷ�Σ�������Ʒ��"; 
}
