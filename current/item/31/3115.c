
// �Զ����ɣ�/make/item/make31b

inherit ITEM;
    inherit COMBINED;

// ��������������
//  int get_max_combined() { return 30; }

// ���������촦��
void create()
{
        set_name("��������Ҷ");
        set_picid_1(3115);
        set_picid_2(3115);
        set_unit("Ƭ");
        set_value(20);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "��Ҷ��һ��"; 
}
