
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8606);
        set_picid_2(8606);

        set_level(50);
        set_value(35000);
        set_max_lasting(5299);
        set("cp", 88);
        set("pp", 56);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
