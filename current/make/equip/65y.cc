
// �Զ����ɣ�/make/equip/65y

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("%s");
        set_picid_1(%d);
        set_picid_2(%d);
        set_unit("%s");

        set_level(%d);
        set_value(%d);
        set_max_lasting(%d);
        set("dp", %d);
        set("pp", %d);
        set("spec.hp", %d);
        set("spec.mp", %d);
        set("spec.??%%", %d);
        set("spec.-*%%", %d);
        set("spec.-c*%%", %d);

        setup();

        set_gender(1);
        set_head_code(%s);
        set_head_color(0x%04x%04x);
}

// ��������ȡ����
string get_desc()
{
        return "%s";
}
