
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(6562);
        set_picid_2(6562);

        set_level(70);
        set_value(22500);
        set_max_lasting(12699);
        set("dp", 82);
        set("pp", 48);

        setup();

        set_gender(1);
        set_head_code(45);
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
