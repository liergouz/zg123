
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("�������");
        set_picid_1(8614);
        set_picid_2(8614);

        set_level(90);
        set_value(71000);
        set_max_lasting(5899);
        set("cp", 170);
        set("pp", 95);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�������";
}
