
// �Զ����ɣ�/make/item/make32a

inherit ITEM;
    inherit COMBINED;

// ��������������
//  int get_max_combined() { return 30; }

// ������ԭ������
int get_stuff_type() { return 170; }

// ���������촦��
void create()
{
        set_name("�̲�");
        set_picid_1(3250);
        set_picid_2(3250);
        set_unit("Ƭ");
        set_value(20);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "ũ��Ʒ��һ��"; 
}
